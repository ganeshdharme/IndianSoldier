#include"precompiled.h"
#include"wall.h"


Wall::Wall()
{

}

Wall::Wall(float x,float y)
{
	m_x=x;
	m_y=y;
	solid=true;
}
void Wall::init()
{

	string path="wall.png ";
	m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
	m_wallimg=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
	solid=true;
}

void Wall::render()
{
	
	m_wallsprite->Render(m_x,m_y);
	m_wallrect->Set(m_x,m_y,m_x+150,m_y+50);
}

void Wall::update()
{
	
}

void Wall::handleInput(IEvent *event)
{
	m_x=m_x-HGE_INSTANCE->Timer_GetDelta()*100;
	if(m_x+150<0)
		WorldMnagaer_getinstance->removeFromActiveList(this);
}

hgeRect* Wall::getObjectRect()
{
	return m_wallrect;
}

void Wall::loadResource()
{
m_wallsprite=new hgeSprite(*m_wallimg->getTexture(),0,0,150,50);
m_wallrect=new hgeRect(m_x,m_y,m_x+150,m_y+50);
}
void Wall::destroy()
{

}