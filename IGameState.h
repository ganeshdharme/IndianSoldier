#pragma once

#include "hgeFont.h"
#include"IEvent.h"
#include"GameAppFramework.h"
class IGameState{

protected:
	hgeFont *m_font;

public:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void handleInput(IEvent*)=0;
	virtual string getResourcevector()=0;
	virtual void loadResource()=0;
};