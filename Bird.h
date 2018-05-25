#pragma once
#include"IObject.h"
#include"ImageResource.h"
#include"IEvent.h"

class Bird:public IObject
{
public:
	float synchvar;
	hgeSprite *m_birdSprite;
	ImageResource *m_birdImage;
	float m_birdxcordinate,m_birdycordinate;
	Bird(float,float);
	Bird();
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
	void setCordinate(float,float);
};