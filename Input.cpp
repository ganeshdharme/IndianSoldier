#include "precompiled.h"
#include "Input.h"

Input::Input(int controller){
	this->controller = controller;
	event = new hgeInputEvent();
}

void Input::reset(){ 
	m_up = m_down = m_left = m_right = m_ctrl = m_space = false;
	m_mouseLeft = m_mouseMiddle = m_mouseRight = false;
	m_mouseDragged = m_mouseReleased = false;
}

void Input::update(HGE* hge){
	reset();
	if(controller == ARROW_CONTROLLER){
		if(hge->Input_GetKeyState(HGEK_UP)) m_up = true;
		if(hge->Input_GetKeyState(HGEK_DOWN)) m_down = true;
		if(hge->Input_GetKeyState(HGEK_LEFT)) m_left = true;
		if(hge->Input_GetKeyState(HGEK_RIGHT)) m_right = true;
		if(hge->Input_GetKeyState(HGEK_CTRL)) m_ctrl = true;
		if(hge->Input_GetKeyState(HGEK_SPACE)) m_space = true;
	}else{
		if(hge->Input_GetKeyState(HGEK_I)) m_up = true;
		if(hge->Input_GetKeyState(HGEK_K)) m_down = true;
		if(hge->Input_GetKeyState(HGEK_J)) m_left = true;
		if(hge->Input_GetKeyState(HGEK_L)) m_right = true;
		if(hge->Input_GetKeyState(HGEK_CAPSLOCK)) m_ctrl = true;
		if(hge->Input_GetKeyState(HGEK_SHIFT)) m_space = true;
	}

	if(hge->Input_GetKeyState(HGEK_LBUTTON)) m_mouseLeft = true;
	if(hge->Input_GetKeyState(HGEK_RBUTTON)) m_mouseRight = true;
	if(hge->Input_GetKeyState(HGEK_MBUTTON)) m_mouseMiddle = true;

	//if(hge->Input_GetEvent(event)){
	//	if(event->type == INPUT_MBUTTONDOWN){
	//		mouseDragged = true;
	//	}
	//	else if(event->type == INPUT_MBUTTONUP){
	//		mouseReleased = true;
	//	}
	//}

	hge->Input_GetMousePos(&m_mouseX, &m_mouseY);
}

float Input::getMouseX(){ return m_mouseX; }
float Input::getMouseY(){ return m_mouseY; }

Input::~Input(void){
}
