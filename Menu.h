#pragma once
#include<future>
#include "Sprite.h"
#include "IGameState.h"
#include "Cursor.h"
#include"ResourceManager.h"
#include"GameStateManager.h"

class Menu : public IGameState
{
private:
	Entity *m_play_sprite, *m_options, *m_exit;
	Sprite *m_cursor;
	KeyEvent* m_keyboardinstance;
	MouseEvent* m_mouseinstance;
	hgeSprite *hg;
	int flag;
	string path;
	 
public:
	Menu(void);
	void Update() override;
	void Render() override;
	void handleInput(IEvent*) override;
	string getResourcevector()override;
	void loadResource()override;
	~Menu(void);
};

