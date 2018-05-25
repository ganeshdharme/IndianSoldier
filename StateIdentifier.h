#pragma once

#ifndef STATE_IDENTIFIER
#define STATE_IDENTIFIER StateIdentifier::GetInstance()
#endif

class StateIdentifier
{
private:
	static StateIdentifier* m_instance;
	StateIdentifier(void);

public:
	enum { MENU = 1, GAME_RUNNING, OPTIONS, EXIT };
	static StateIdentifier* GetInstance();

	~StateIdentifier(void);
};

