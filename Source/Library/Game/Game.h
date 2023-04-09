#include "Common.h"

LRESULT CALLBACK WindowProc(
	_In_ HWND hWnd,
	_In_ UINT uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);

HRESULT InitWindow(_In_ HINSTANCE hInstance, _In_ INT nCmdShow);
HRESULT InitDevice();

void CleanupDevice();
void Render();

struct SimpleVertex 
{
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
};

HRESULT CompileShaderFromFile
(
	_In_ PCWSTR pszFileName, // FileName
	_In_ PCSTR pszEntryPoint, // EntryPoint
	_In_ PCSTR pszShaderModel, // Shader target 
	_Outptr_ ID3DBlob** ppBlobOut // ID3DBlob out
);

struct ConstantBuffer
{
	XMMATRIX World;
	XMMATRIX View;
	XMMATRIX Projection;
};