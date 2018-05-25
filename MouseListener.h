#pragma  once

#include "IListener.h"

class MouseListener : public IListener
{

public:
	virtual void onClick() = 0;
	virtual void onNotify(IEvent*) = 0;

};