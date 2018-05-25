#pragma once
#include"IGameState.h"
#include<vector>
#include<algorithm>
#include"IListner.h"
#ifndef BROADCASTER
#define BROADCASTER Broadcaster::GetInstance()
#endif
using namespace std;
class Broadcaster
{
private:
	static Broadcaster* m_instance;
vector<IListner*> m_listner;
	Broadcaster();

public:

	void registerForEvent(IListner*);
	void UnregisterForEvent(IListner*);
	void onEventHappen(IEvent*);

	static Broadcaster* GetInstance();

	~Broadcaster(void);
};

