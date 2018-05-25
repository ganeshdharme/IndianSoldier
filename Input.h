#pragma once

#include "hge.h"

class Input
{
private:
	enum { ARROW_CONTROLLER = 1, IJKL_CONTOLLER };
	hgeInputEvent *event;
	int controller;
public:
	 bool m_up, m_down,  m_left,  m_right,  m_ctrl,  m_space;
	 bool m_mouseLeft,  m_mouseRight,  m_mouseMiddle;
	 bool  m_mouseDragged;
	 bool  m_mouseReleased;
	 float  m_mouseX,  m_mouseY;

public:
	Input(int);

	void reset();
	void update(HGE*);
	float getMouseX();
	float getMouseY();

	~Input(void);

};

