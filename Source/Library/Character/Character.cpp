#include "Character/Character.h"

Character::Character()
	: Model("../../Data/Stone/Stone.obj")
	, m_targetPosition(DEFAULT_RIGHT)
	, m_currentPosition(DEFAULT_FORWARD)
	, m_moveLeftRight(0.0f)
	, m_moveBackForward(0.0f)
	, m_currentDirection(DOWN)
	, m_targetDirection(DOWN)
	, m_movementSpeed(10.0f)
{
}

Character::Character(_In_ const std::filesystem::path& filePath)
	: Model(filePath)
	, m_targetPosition(DEFAULT_RIGHT)
	, m_currentPosition(DEFAULT_FORWARD)
	, m_moveLeftRight(0.0f)
	, m_moveBackForward(0.0f)
	, m_currentDirection(DOWN)
	, m_targetDirection(DOWN)
	, m_movementSpeed(10.0f)
{
}

void Character::HandleInput(_In_ const InputDirections& directions, _In_ FLOAT deltaTime)
{
	if (directions.bFront)
	{
		m_targetDirection = UP;
		m_moveBackForward += m_movementSpeed * deltaTime;
	}

	if (directions.bLeft)
	{
		m_targetDirection = LEFT;
		m_moveLeftRight -= m_movementSpeed * deltaTime;
	}

	if (directions.bBack)
	{
		m_targetDirection = DOWN;
		m_moveBackForward -= m_movementSpeed * deltaTime;
	}

	if (directions.bRight)
	{
		m_targetDirection = RIGHT;
		m_moveLeftRight += m_movementSpeed * deltaTime;
	}
}

void Character::Update(_In_ FLOAT deltaTime)
{	
	// 회전
	switch (m_targetDirection)
	{
	case UP:
		if (m_currentDirection != m_targetDirection) {
			RotateYInObjectCoordinate(m_currentDirection - m_targetDirection, m_currentPosition);
			m_currentDirection = m_targetDirection;
		}
		break;
	case LEFT:
		if (m_currentDirection != m_targetDirection) {
			RotateYInObjectCoordinate(m_currentDirection - m_targetDirection, m_currentPosition);
			m_currentDirection = m_targetDirection;
		}
		break;
	case DOWN:
		if (m_currentDirection != m_targetDirection) {
			RotateYInObjectCoordinate(m_currentDirection - m_targetDirection, m_currentPosition);
			m_currentDirection = m_targetDirection;
		}

		break;
	case RIGHT:
		if (m_currentDirection != m_targetDirection) {
			RotateYInObjectCoordinate(m_currentDirection - m_targetDirection, m_currentPosition);
			m_currentDirection = m_targetDirection;
		}
		break;
	default:
		break;
	}

	// 이동
	m_targetPosition += m_moveLeftRight * DEFAULT_RIGHT;
	m_targetPosition += m_moveBackForward * DEFAULT_FORWARD;

	Translate(m_targetPosition - m_currentPosition);

	m_moveLeftRight = 0.0f;
	m_moveBackForward = 0.0f;

	m_currentPosition = m_targetPosition;
}
