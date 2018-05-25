#pragma once

#include"KeyEvent.h"
#include"MouseEvent.h"
#include"IEvent.h"
#include<windows.h>
#define INPUT_INSTANCE InputManager::GetInstance()

#define BUTTON_LEFT		1
#define BUTTON_UP		2
#define BUTTON_RIGHT	3
#define BUTTON_DOWN		4

#define BUTTON_SPACE	5
#define BUTTON_CTRL		6
#define BUTTON_ESCAPE	7

class InputManager
{
private:
	bool m_keys[20];
	bool m_keypressflag,m_mouspressflag;
	InputManager(void);
	static InputManager* m_instance;
	float m_mxc,m_myc;
public:
	void Reset();
	void Update();
	bool keyboardpressed();
	bool onmouseClicked();
	void BroadcastEvent(IEvent*);
	static InputManager* GetInstance();
	~InputManager(void);
};

