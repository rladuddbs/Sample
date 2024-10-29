#pragma once
#include "Scene.h"

class CMenuScene : public CScene
{
public:
	CMenuScene();
	~CMenuScene();


	virtual void Initialize(HWND hwnd, HINSTANCE g_hInst);

	virtual void ProcessInput();

	virtual void Update();
	virtual void Render();



private:
	HBITMAP			 backgroundImage;

};


