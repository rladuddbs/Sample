#pragma once
#include "Scene.h"


#pragma once
#include "Scene.h"

#pragma once
#include "Scene.h"

#pragma once
#include "Scene.h"

class CLobbyScene : public CScene
{
public:
	CLobbyScene();
	~CLobbyScene();

	virtual void Initialize(HWND hwnd, HINSTANCE g_hInst);

	virtual void ProcessInput();

	virtual void Update();
	virtual void Render();


private:
	HBITMAP			 backgroundImage;

};




