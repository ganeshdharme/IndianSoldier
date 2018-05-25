#include"precompiled.h"
#include"Bullet.h"
Bullet::Bullet(float x,float y)
{
	m_bulletxcordinate=x+92;
	m_bulletycordinate=y+45;
	if(x==true)
	{
		m_bulletSprite->SetFlip(x,y);
	}
	solid=true;
}
Bullet::Bullet()
{

}
void Bullet::init()
{
	string path="Bullet.png ";
	m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
	m_bulletImage=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
	//m_bulletxcordinate=92,m_bulletycordinate=45;
}

void Bullet::loadResource()
{
	m_bulletSprite=new hgeSprite(*m_bulletImage->getTexture(),0,0,20,8);
	m_objectrect=new hgeRect(m_bulletxcordinate,m_bulletycordinate,m_bulletxcordinate+20,m_bulletycordinate+8);
}

void Bullet::handleInput(IEvent *event)
{
	
}
void Bullet::render()
{
	m_bulletSprite->Render(m_bulletxcordinate,m_bulletycordinate);
	m_objectrect->Set(m_bulletxcordinate,m_bulletycordinate,m_bulletxcordinate+20,m_bulletycordinate+8);
}
void Bullet::update()
{
	m_bulletxcordinate+=HGE_INSTANCE->Timer_GetDelta()*100;
	if(m_bulletxcordinate>1200)
		WorldMnagaer_getinstance->removeFromActiveList(this);
		//,m_bulletycordinate=45;
}
void Bullet::destroy()
{

}
hgeRect* Bullet::getObjectRect()
{
	return m_objectrect;
}
void Bullet::setCordinate(float x,float y)
{
}




