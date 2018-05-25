#pragma once

#include "IGameState.h"
#include"Player.h"
#include <future>
#include"GameBackground.h"
#include"Hurdles.h"
#include "GameAppFramework.h"
#include"ResourceTracker.h"
#include"IResource.h"
#include"WorldManager.h"
class GameRunning : public IGameState
{
private:
	KeyEvent* m_keyboardinstance;
	MouseEvent* m_mouseinstance;
	Player *m_playerInstance;
	BackgroundImage *m_backgroundImg;
	string m_pathvector;
	ImageResource *m_receivedir;
	vector<IResource*> m_receivedresources;
	WorldManager *m_wmanager;

public:
	GameRunning(void);
	void Update() override;
	void Render() override;
	void handleInput(IEvent*) override;
	~GameRunning(void);
	string getResourcevector()override;
	 void loadResource()override;
};

