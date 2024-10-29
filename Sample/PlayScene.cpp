#include "PlayScene.h"
#include "Windows.h"

CPlayScene::CPlayScene()
{
	player = NULL;

}

CPlayScene::~CPlayScene()
{
}

void CPlayScene::Initialize(HWND hwnd, HINSTANCE g_hInst)
{
	CScene::Initialize(hwnd, g_hInst);

	backgroundImage = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_STAGEFRAME));
}


void CPlayScene::ProcessInput()
{
	static UCHAR pKeysBuffer[256];
	bool bProcessedByScene = false;
	GetKeyboardState(pKeysBuffer);
	if (pKeysBuffer[VK_UP] & 0xF0) Beep(100, 1000);
	/*if (pKeysBuffer[VK_DOWN] & 0xF0) dwDirection |= DIR_BACKWARD;
	if (pKeysBuffer[VK_LEFT] & 0xF0) dwDirection |= DIR_LEFT;
	if (pKeysBuffer[VK_RIGHT] & 0xF0) dwDirection |= DIR_RIGHT;
	if (pKeysBuffer[VK_PRIOR] & 0xF0) dwDirection |= DIR_UP;
	if (pKeysBuffer[VK_NEXT] & 0xF0) dwDirection |= DIR_DOWN;

	if (pKeysBuffer['W'] & 0xF0) dwDirection |= DIR_FORWARD;
	if (pKeysBuffer['S'] & 0xF0) dwDirection |= DIR_BACKWARD;
	if (pKeysBuffer['A'] & 0xF0) dwDirection |= DIR_LEFT;*/
}

void CPlayScene::Update()
{
}

void CPlayScene::Render()
{
	HDC hdc = GetDC(hWnd);

	HDC MemDC = CreateCompatibleDC(hdc);
	HDC MemDCImage = CreateCompatibleDC(hdc);

	hBit = CreateCompatibleBitmap(hdc, rc.right, rc.bottom);
	OldBit[0] = (HBITMAP)SelectObject(MemDC, hBit);
	OldBit[1] = (HBITMAP)SelectObject(MemDCImage, backgroundImage); //--- ��� �̹���	

	//StretchBlt(MemDC, 0, 0, FRAME_BUFFER_WIDTH, FRAME_BUFFER_HEIGHT, MemDCImage, 0, 0, 810, 650, SRCCOPY);
	TransparentBlt(MemDC, 0, 0, rc.right, rc.bottom, MemDCImage, 0, 0, 800, 600, RGB(255, 0, 255));

	BitBlt(hdc, 0, 0, rc.right, rc.bottom, MemDC, 0, 0, SRCCOPY);

	// �ڿ� ����
	SelectObject(MemDC, OldBit[0]);
	DeleteObject(hBit);
	DeleteDC(MemDC);
	DeleteDC(MemDCImage);
	ReleaseDC(hWnd, hdc);
}
