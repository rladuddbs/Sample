#include "GameFramework.h"
#include "stdafx.h"


CGameFramework::CGameFramework()
{
	scene			= nullptr;

	scenes			= new CScene * [4];		// ¾À 4°³
	currentscene	= LOBBYSCENE;			// SceneÀÇ ÀÎµ¦½º

}

CGameFramework::~CGameFramework()
{
}

void CGameFramework::Initialize(HWND hMainWnd, HINSTANCE g_hInst)
{
	hWnd = hMainWnd;
	hInst = g_hInst;
	scenes[0] = new CStartScene();
	scenes[0]->Initialize(hWnd, hInst);

	scenes[1] = new CMenuScene();
	scenes[1]->Initialize(hWnd, hInst);

	scenes[2] = new CLobbyScene();
	scenes[2]->Initialize(hWnd, hInst);

	scenes[3] = new CPlayScene();
	scenes[3]->Initialize(hWnd, hInst);


	scene = scenes[currentscene];
}

void CGameFramework::FrameAdvance()
{
	Update();
	Render();
}

void CGameFramework::Update()
{
	Tick();

	scene->Update();
}

void CGameFramework::Tick()
{

}



void CGameFramework::Render()
{
	scene->Render();
}

void CGameFramework::ProcessInput()
{
	NextScene();
	scene->ProcessInput();
}

void CGameFramework::NextScene()
{
	currentscene = (currentscene + 1) % 4;
	scene = scenes[currentscene];
}
