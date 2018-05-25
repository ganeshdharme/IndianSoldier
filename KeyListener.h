#pragma  once

#include "IListener.h"

class KeyListener : public IListener
{

public:
	virtual void isPressed() = 0;
	virtual void isReleased() = 0;
	virtual void isTyped() = 0;
	virtual void onNotify(IEvent*) = 0;

};