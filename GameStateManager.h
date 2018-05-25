#pragma once

#include <stack>
#include"Broadcaster.h"
#include "InputManager.h"
#include "IGameState.h"
#include "Menu.h"
#include "GameRunning.h"
#include "LoadingState.h"
#include "IEvent.h"
#include "IListner.h"
#include "KeyEvent.h"
#include "MouseEvent.h"
#include"GameAppFramework.h"
class GameStateManager:public IListner
{
private:
	GameStateManager();
	KeyEvent* m_keyboardinstance;
	MouseEvent* m_mouseinstance;
	static GameStateManager* m_instance;
	std::stack<IGameState*> m_states;

public:
	void Update();
	void Render();
	void Push(IGameState*);
	void Pop();
	void onNotify(IEvent*)override;
	static GameStateManager* GetInstance();
	~GameStateManager();
	
};

