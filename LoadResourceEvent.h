#include"IEvent.h"
class LoadResourceEvent:public IEvent
{
public:
	enum Load
	{
		RUNNING
	};
	Load m_currentload;
};