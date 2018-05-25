#include"precompiled.h"
#include"Bird.h"

Bird::Bird(float x,float y)
{
	m_birdxcordinate=0;
	m_birdycordinate=0;
	synchvar=1;
	if(x==true)
	{
		m_birdSprite->SetFlip(x,y);
	}
}
Bird::Bird()
{
	m_birdxcordinate=0;
	m_birdycordinate=0;
	
}
void Bird::init()
{
	string path="birdsprite.png ";
	m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
	m_birdImage=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
	//m_bulletxcordinate=92,m_bulletycordinate=45;
}

void Bird::loadResource()
{
	m_birdSprite=new hgeSprite(*m_birdImage->getTexture(),0,0,1200,1256);
	HTEXTURE tex=*m_birdImage->getTexture();
	m_objectrect=new hgeRect(m_birdxcordinate,m_birdycordinate,m_birdxcordinate+240,m_birdycordinate+251);
	
	//m_birdSprite->SetTextureRect(m_birdxcordinate,m_birdycordinate,m_birdxcordinate+240,m_birdycordinate+251);
}

void Bird::handleInput(IEvent *event)
{

			synchvar+=m_birdxcordinate+=HGE_INSTANCE->Timer_GetDelta()*10;
	if(synchvar>240)
{
	synchvar=1;
	m_birdxcordinate=m_birdxcordinate+240;
	}	
}
void Bird::render()
{
	
	m_birdSprite->SetTextureRect(m_birdxcordinate,m_birdycordinate,m_birdxcordinate+240,m_birdycordinate+251);
 	m_birdSprite->Render(m_birdxcordinate,m_birdycordinate);
	
}
void Bird::update()
{
	//m_birdxcordinate+=HGE_INSTANCE->Timer_GetDelta()*100;

	
		//,m_bulletycordinate=45;


}
void Bird::destroy()
{

}
hgeRect* Bird::getObjectRect()
{
	return m_objectrect;
}
void Bird::setCordinate(float x,float y)
{
}
