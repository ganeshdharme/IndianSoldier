#pragma once
#include"IObject.h"
#include"IEvent.h"
class Bullet :public IObject
{
public:
	hgeSprite *m_bulletSprite;
	ImageResource *m_bulletImage;
	float m_bulletxcordinate,m_bulletycordinate;
	Bullet(float,float);
	Bullet();
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
	void setCordinate(float,float);
};