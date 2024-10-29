#pragma once
#include "Scene.h"

class CPlayScene : public CScene
{
public:
	CPlayScene();
	~CPlayScene();

	virtual void Initialize(HWND hwnd, HINSTANCE g_hInst);

	virtual void ProcessInput();


	virtual void Update();
	virtual void Render();




private:
	HBITMAP			 backgroundImage;


	CPlayer* player;			// 플레이어

};
