#pragma once

#ifndef HGE_INSTANCE
#define HGE_INSTANCE GameAppFramework::GetInstance()->getHGE()
#endif

#include "InputManager.h"
#include "GameStateManager.h"
#include"ResourceTracker.h"

class GameAppFramework
{
private:
	GameAppFramework();
	static GameAppFramework *m_instance;
	HGE* m_hge;

public:
	void init();

	static bool HGEUpdateCallback();
	static bool HGERenderCallback();

	bool Update();
	bool Render();

	HGE* getHGE();
	static GameAppFramework* GetInstance();

	~GameAppFramework(void);
};
