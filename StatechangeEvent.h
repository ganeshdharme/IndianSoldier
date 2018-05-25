#pragma once
#include"IEvent.h"
class StateChangeEvent:public IEvent
{
public:
	enum States
	{
		MENU,
		RUNNING,
		LOADING,
		EXIT
	};
	States mcurrentstate;
	~StateChangeEvent()override;
};