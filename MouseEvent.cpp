#include"precompiled.h"
#include"MouseEvent.h"

void MouseEvent::clearMPostion()
{
	m_mousex=0;
	 m_mousey=0;
}
void MouseEvent::Listen()
{
	clearMPostion();
	HGE_INSTANCE->Input_GetMousePos(& m_mousex,& m_mousey);
}

MouseEvent::MouseEvent(float i_mousex,float i_mousey)
{
	this-> m_mousex=i_mousex;
	this-> m_mousey=i_mousey;
}

MouseEvent::~MouseEvent()
{
}