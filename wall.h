#pragma once
#include"IObject.h"
#include"IEvent.h" 
class Wall:public IObject
{
	private:
	ImageResource *m_wallimg;
	hgeSprite *m_wallsprite;
	float m_x,m_y;
	hgeRect *m_wallrect;
public:
	Wall();
	Wall(float,float);
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
};