#include"precompiled.h"
#include"Bomb.h"

void Bomb::init()
{

	string path="rock.png ";
	m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
	bomb_img=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
}

void Bomb::render()
{
	if(m_x=3000)
	m_bombsprite->Render(800,550-64);
}

void Bomb::update()
{
	
}

void Bomb::handleInput(IEvent *event)
{

}

hgeRect* Bomb::getObjectRect()
{
	return NULL;
}
Bomb::Bomb()
{

}
void Bomb::loadResource()
{
m_bombsprite=new hgeSprite(*bomb_img->getTexture(),0,0,50,64);
m_bombrect=new hgeRect(0,0,0,0);
}
void Bomb::destroy()
{

}