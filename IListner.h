#pragma once
#include"IEvent.h"
class IListner
{
public:
		virtual void onNotify(IEvent*)=0;
};