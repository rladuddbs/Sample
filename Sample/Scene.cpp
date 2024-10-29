#include "Scene.h"

CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::Initialize(HWND hwnd, HINSTANCE g_hInst)
{
	hWnd = hwnd;
	hInst = g_hInst;
	GetClientRect(hWnd, &rc);

}



