#pragma once

#include "IEvent.h"

#define LEFT_BUTTON
#define RIGHT_BUTTON
#define MIDDLE_BUTTON

class MouseEvent : public IEvent
{
public:
	float m_mousex,m_mousey;
	void clearMPostion();
	void Listen();
	MouseEvent(float i_mousex,float i_mousey);
	~MouseEvent()override;

};