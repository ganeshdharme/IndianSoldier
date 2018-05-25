#include "precompiled.h"
#include "GameStateManager.h"
#include"StatechangeEvent.h"
#include"LoadResourceEvent.h"
#ifndef GAME_STATE_MANAGER
#define GAME_STATE_MANAGER GameStateManager::GetInstance()
#endif

GameStateManager* GameStateManager::m_instance = 0;

GameStateManager::GameStateManager(){
	Push(new Menu());
	BROADCASTER->registerForEvent(this);
}

void GameStateManager::Update(){
	m_states.top()->Update();
}

void GameStateManager::onNotify(IEvent *event)
{

	if(dynamic_cast<StateChangeEvent*>(event))
	{
		StateChangeEvent *ch= dynamic_cast<StateChangeEvent*>(event);
		switch (ch->mcurrentstate)
		{
		case ch->RUNNING:
			Push(new GameRunning());
			//m_states.top()->loadResource();
			ch->mcurrentstate=ch->RUNNING;
			break;
		case ch->MENU:
			Pop();
			ch->mcurrentstate=ch->MENU;
			break;
		case ch->LOADING:
			
			break;
		default:
			break;
		}
	}
	else if(dynamic_cast<KeyEvent*>(event))
		m_states.top()->handleInput(event);

}


void GameStateManager::Render()
{
	m_states.top()->Render();
}

void GameStateManager::Push(IGameState* newState)
{
	m_states.push(newState);
	
}

void GameStateManager::Pop()
{
	if(m_states.size() > 1)
		{
			IGameState *ptr=m_states.top();
			GameRunning *igame;
			if(igame=dynamic_cast<GameRunning*>(ptr))
				delete igame;
			m_states.pop();
		}
}

GameStateManager* GameStateManager::GetInstance(){
	if(m_instance == NULL) 
		m_instance = new GameStateManager();
	
	return m_instance;
}

GameStateManager::~GameStateManager(){
}
