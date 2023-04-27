#pragma once

#include "Common.h"

// Structure declaration
struct SimpleVertex
{
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
};

struct ConstantBuffer
{
	XMMATRIX World;
	XMMATRIX View;
	XMMATRIX Projection;
};

struct InputDirections	// input type
{
	BOOL bFront;
	BOOL bBack;
	BOOL bLeft;
	BOOL bRight;
	BOOL bUp;
	BOOL bDown;
};

struct MouseRelativeMovement
{
	LONG X;
	LONG Y;
};

// Function declaration
LRESULT CALLBACK WindowProc(_In_ HWND hWnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

HRESULT InitWindow(_In_ HINSTANCE hInstance, _In_ INT nCmdShow);
HRESULT InitDevice();
HRESULT CompileShaderFromFile(_In_ PCWSTR pszFileName, _In_ PCSTR pszEntryPoint, _In_ PCSTR pszShaderModel, _Outptr_ ID3DBlob** ppBlobOut);

void CleanupDevice();
void Render();
void HandleInput(FLOAT deltaTime);
void Update(FLOAT deltaTime);