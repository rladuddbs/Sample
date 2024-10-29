#pragma once
#include "stdafx.h"
#include "Scene.h"

class CStartScene : public CScene
{
public:
	CStartScene();
	~CStartScene();



	virtual void Initialize(HWND hwnd, HINSTANCE g_hInst);

	virtual void ProcessInput();

	virtual void Update();
	virtual void Render();


private:

};
