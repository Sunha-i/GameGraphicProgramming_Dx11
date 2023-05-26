#pragma once

#include "Common.h"

#include "Model/Model.h"

enum CharacterDirection
{
	UP = 0,
	LEFT = 90,
	DOWN = 180,
	RIGHT = 270
};

class Character : public Model
{
public:
	Character();
	Character(_In_ const std::filesystem::path& filePath);
	~Character() = default;

	void HandleInput(_In_ const InputDirections& directions, _In_ FLOAT deltaTime);
	void Update(_In_ FLOAT deltaTime);


private:
	const XMVECTORF32 DEFAULT_FORWARD = { 0.0f, 0.0f, 1.0f, 0.0f };
	const XMVECTORF32 DEFAULT_RIGHT = { 1.0f, 0.0f, 0.0f, 0.0f };
	
	XMVECTOR m_targetPosition;
	XMVECTOR m_currentPosition;
	FLOAT m_moveLeftRight;
	FLOAT m_moveBackForward;

	CharacterDirection m_currentDirection;
	CharacterDirection m_targetDirection;

	
	FLOAT m_movementSpeed;
};