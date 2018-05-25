#pragma once

#include "IEvent.h"
#include<iostream>
using namespace std;

#define BUTTON_LEFT		1
#define BUTTON_UP		2
#define BUTTON_RIGHT	3
#define BUTTON_DOWN		4

#define BUTTON_SPACE	5
#define BUTTON_CTRL		6
#define BUTTON_ESCAPE	7

class KeyEvent : public IEvent
{
private:
	bool m_keys[20];
	
public:
	
	KeyEvent(bool[]);
	bool isKeyPressed(int);
	void Reset();
	~KeyEvent()override;

};