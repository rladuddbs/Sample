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

	CTimer			timer;			// Ÿ�̸�

	int				currentscene;			// Scene�� �ε���
	CScene*			scene;			// ��
	CScene**		scenes;			// ��� ��

	HDC hdc, MemDC, MemDCImage;
	PAINTSTRUCT ps;

public:
	void NextScene();				//������ �� �ѱ��






private:
	





};

