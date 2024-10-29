#include "StartScene.h"

CStartScene::CStartScene()
{
}

CStartScene::~CStartScene()
{
}

void CStartScene::Initialize(HWND hwnd, HINSTANCE g_hInst)
{
	CScene::Initialize(hwnd, g_hInst);

}


void CStartScene::ProcessInput()
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

void CStartScene::Update()
{
}

void CStartScene::Render()
{
	static RECT rect = { 50, 50, 200, 150 };
	rect.left += 1;
	rect.top += 1;
	rect.right += 1;
	rect.bottom += 1;
	//InvalidateRect(hwnd, NULL, TRUE);  // TRUE로 설정해 배경을 지웁니다.
	HDC hdc = GetDC(hWnd);
	MemDC = CreateCompatibleDC(hdc); //--- 더블 버퍼로 사용 할 메모리 DC 생성
	
	hBit = CreateCompatibleBitmap(hdc, FRAME_BUFFER_WIDTH, FRAME_BUFFER_HEIGHT);
	OldBit[0] = (HBITMAP)SelectObject(MemDC, hBit); //--- MemDC와 hBit 를 호환되게 선택함
	// 빨간색 브러시 생성
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	
	FillRect(MemDC, &rect, redBrush);

	BitBlt(hdc, 0, 0, FRAME_BUFFER_WIDTH, FRAME_BUFFER_HEIGHT, MemDC, 0, 0, SRCCOPY);
	// 자원 해제
	DeleteObject(redBrush);
	SelectObject(MemDC, OldBit);             // 이전 비트맵으로 복구
	DeleteObject(hBit);                      // 비트맵 삭제
	DeleteDC(MemDC);                            // 메모리 DC 삭제
	ReleaseDC(hWnd, hdc);                       // 화면 DC 해제

	//hdc = BeginPaint(hwnd, &ps);	
	////hBit = CreateCompatibleBitmap(hdc, FRAME_BUFFER_WIDTH, FRAME_BUFFER_HEIGHT);
	//HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	//RECT rect = { 50, 50, 200, 150 };
	//FillRect(hdc, &rect, redBrush);

	//// 브러시 자원 해제
	//DeleteObject(redBrush);
	////MemDC = CreateCompatibleDC(hdc); //--- 더블 버퍼로 사용 할 메모리 DC 생성
	////MemDCImage = CreateCompatibleDC(MemDC); //--- 이미지를 저장 할 메모리 DC 생성
	////OldBit[0] = (HBITMAP)SelectObject(MemDC, hBit); //--- MemDC와 hBit 를 호환되게 선택함
	////Rectangle(MemDC, 0, 0, 200, 200);
	//////OldBit[1] = (HBITMAP)SelectObject(MemDCImage, login/*비트맵이미지*/); //--- 배경 이미지	
	////StretchBlt(MemDC, 0, 0, FRAME_BUFFER_WIDTH, FRAME_BUFFER_HEIGHT, MemDCImage, 0, 0, 1220, 950, SRCCOPY);

	////BitBlt(hdc, 0, 0, FRAME_BUFFER_WIDTH, FRAME_BUFFER_HEIGHT, MemDC, 0, 0, SRCCOPY);
	//EndPaint(hwnd, &ps);



}
