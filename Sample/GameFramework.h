#pragma once
#include "Timer.h"
#include "Scene.h"

#include "StartScene.h"
#include "MenuScene.h"
#include "LobbyScene.h"
#include "PlayScene.h"


#include "stdafx.h"
class CGameFramework
{
public:
	CGameFramework();
	~CGameFramework();

	void Initialize(HWND hMainWnd, HINSTANCE g_hInst);

	void FrameAdvance();

	void Tick();
	void Update();
	void Render();

	void ProcessInput();
private:
	HWND			hWnd;
	HINSTANCE		hInst;

	CTimer			timer;			// Å¸ÀÌ¸Ó

	int				currentscene;			// SceneÀÇ ÀÎµ¦½º
	CScene*			scene;			// ¾À
	CScene**		scenes;			// ¸ðµç ¾À

	HDC hdc, MemDC, MemDCImage;
	PAINTSTRUCT ps;

public:
	void NextScene();				//µð¹ö±ë¿ë ¾À ³Ñ±â±â






private:
	





};

