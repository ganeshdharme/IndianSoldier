#pragma once
#include"ResourceManager.h"
#include"ImageResource.h"
#include"IObject.h"
#include<future>
class BackgroundImage:public IObject
{
public:
	ImageResource* imager;
	std::future<IResource*> future1;
	std::promise<IResource*> promise1;
	IResource *ir;
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent *event)override;
	void loadResource()override;
	void destroy()override;
	hgeRect *getObjectRect()override;
	hgeSprite *m_backgroundsprite;
	float m_x, m_y,m_x2,m_y2;
	hgeRect *m_hurdlerect;
	BackgroundImage(string paths);
	BackgroundImage();
	HTEXTURE *m_tex;
	hgeFont *m_font;
};