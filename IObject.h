#pragma once
#include"IResource.h"
class IObject
{
public:
	int m_objectid;
	bool solid;
	hgeRect *m_objectrect;
	vector<IResource*> m_receivedresources;
	virtual void update();
	virtual void render();
	virtual void init();
	virtual void destroy();
	virtual void handleInput(IEvent *event);
	virtual void loadResource();
	bool isAllResourceLoaded();
	virtual hgeRect* getObjectRect();
	bool isSolid();
	 
};