#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "Player.h"

class CScene
{
public:
	CScene();
	~CScene();


	virtual void Initialize(HWND hwnd, HINSTANCE g_hInst);
	virtual void ProcessInput() = 0;


	virtual void Update() = 0;
	virtual void Render() = 0;




protected:
	HWND			hWnd;
	HINSTANCE		hInst;
	RECT rc;


	HBITMAP			hBit;
	HDC				MemDC;
	HDC				MemDCImage;
	HBITMAP			OldBit[2];
};






