#include "precompiled.h"
#include"InputManager.h"
InputManager* InputManager::m_instance = 0;

InputManager::InputManager(void){
}

void InputManager::Reset(){
	for(int i=0; i<20; i++){
		m_keys[i] = false;
	}
	m_mxc=0;
	m_myc=0;
	m_keypressflag=false;
}



bool InputManager::onmouseClicked()
{
	//Reset();
	HGE_INSTANCE->Input_GetMousePos(&m_mxc,&m_myc);
	if(m_mxc==m_myc==0)
		return !true;
}





void InputManager::Update(){
	 
  	if(	keyboardpressed())
  		BroadcastEvent(new KeyEvent(m_keys));
	/*if(onmouseClicked())
		BroadcastEvent(new MouseEvent(m_mxc,m_myc));*/
	//Reset();

}

bool InputManager::keyboardpressed()
{
	Reset();

		if(GetAsyncKeyState(VK_SPACE)& 0xFF){m_keys[BUTTON_SPACE] = true;m_keypressflag=true;}
		if(GetAsyncKeyState(VK_UP)&&!m_keys[BUTTON_UP] ){m_keys[BUTTON_UP] = true;m_keypressflag=true;}
		if(GetAsyncKeyState(VK_DOWN)){m_keys[BUTTON_DOWN] = true;m_keypressflag=true;}
 		if(GetAsyncKeyState(VK_LEFT)){m_keys[BUTTON_LEFT] = true;m_keypressflag=true;}
		if(GetAsyncKeyState(VK_RIGHT)){m_keys[BUTTON_RIGHT] = true;m_keypressflag=true;}
		if(GetAsyncKeyState(VK_CONTROL)){m_keys[BUTTON_CTRL] = true;m_keypressflag=true;}
		if(GetAsyncKeyState(VK_ESCAPE)){m_keys[BUTTON_ESCAPE&0xFF] = true;m_keypressflag=true;}

		return m_keypressflag;
}


void InputManager::BroadcastEvent(IEvent *i)
{
	BROADCASTER->onEventHappen(i);
}


InputManager* InputManager::GetInstance(){
	if(m_instance == NULL)
		m_instance = new InputManager();
	return m_instance;
}

InputManager::~InputManager(void){
}
