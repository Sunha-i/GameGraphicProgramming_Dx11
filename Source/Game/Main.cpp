﻿#include "Common.h"

#include "Cube/Cube.h"
#include "Game/Game.h"
#include "Character/Character.h"

INT WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ INT nCmdShow)
{
	std::unique_ptr<Game> game = std::make_unique<Game>(L"GGP : Model Loading with OOD");

    // Phong Lighting Shaders
    std::shared_ptr<VertexShader> vertexShader = std::make_shared<VertexShader>(L"Shaders/Shader.fx", "VS", "vs_5_0");
    if (FAILED(game->GetRenderer()->AddVertexShader(L"VS", vertexShader)))
        return 0;

    std::shared_ptr<PixelShader> pixelShader = std::make_shared<PixelShader>(L"Shaders/Shader.fx", "PS", "ps_5_0");
    if (FAILED(game->GetRenderer()->AddPixelShader(L"PS", pixelShader)))
        return 0;

    std::shared_ptr<PixelShader> pixelSolidShader = std::make_shared<PixelShader>(L"Shaders/Shader.fx", "PSSolid", "ps_5_0");
    if (FAILED(game->GetRenderer()->AddPixelShader(L"PSSolid", pixelSolidShader)))
        return 0;

    // Point Light
    XMFLOAT4 color;
    XMStoreFloat4(&color, Colors::AntiqueWhite);
    std::shared_ptr<PointLight> pointLight = std::make_shared<PointLight>(XMFLOAT4(-5.77f, 7.77f, -5.77f, 1.0f), color);

    if (FAILED(game->GetRenderer()->AddPointLight(0u, pointLight)))
        return 0;

    // Point Light Cube
    std::shared_ptr<Cube> lightCube = std::make_shared<Cube>(color);
    lightCube->Translate(XMVectorSet(-5.77f, 7.77f, -5.77f, 0.0f));
    if (FAILED(game->GetRenderer()->AddRenderable(L"LightCube", lightCube)))
        return 0;
    if (FAILED(game->GetRenderer()->SetVertexShaderOfRenderable(L"LightCube", L"VS")))
        return 0;
    if (FAILED(game->GetRenderer()->SetPixelShaderOfRenderable(L"LightCube", L"PSSolid")))
        return 0;

    // Stone Character
    std::shared_ptr<Character> stone = std::make_shared<Character>();
    stone->Scale(0.5f, 0.5f, 0.5f);
    game->GetRenderer()->SetCharacter(stone);
    if (FAILED(game->GetRenderer()->AddRenderable(L"Stone", stone)))
        return 0;
    if (FAILED(game->GetRenderer()->SetVertexShaderOfRenderable(L"Stone", L"VS")))
        return 0;
    if (FAILED(game->GetRenderer()->SetPixelShaderOfRenderable(L"Stone", L"PS")))
        return 0;

    if (FAILED(game->Initialize(hInstance, nCmdShow)))
        return 0;

    return game->Run();
}