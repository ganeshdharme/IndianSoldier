#include"precompiled.h"
#include"Tank.h"


void Tank::init()
{

	string path="rock.png ";
	m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
	tank_img=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
}

void Tank::render()
{
	if(m_x=3000)
	m_tanksprite->Render(800,550-64);
}

void Tank::update()
{
	
}

void Tank::handleInput(IEvent *event)
{

}

hgeRect* Tank::getObjectRect()
{
	return NULL;
}
Tank::Tank()
{

}
void Tank::loadResource()
{
m_tanksprite=new hgeSprite(*tank_img->getTexture(),0,0,50,64);
m_tankrect=new hgeRect(0,0,0,0);
}
void Tank::destroy()
{

}