#include "precompiled.h"
#include "KeyEvent.h"

KeyEvent::KeyEvent(bool keys[])
{
	for(int i=0;i<20;i++)
		this-> m_keys[i]=keys[i];
}

bool KeyEvent::isKeyPressed(int key)
{
	return  m_keys[key];
}

void KeyEvent::Reset(){
	for(int i=0; i<20; i++){
		m_keys[i] = false;
	}
}
KeyEvent::~KeyEvent()
{

}