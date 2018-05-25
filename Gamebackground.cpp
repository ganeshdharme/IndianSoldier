#include"precompiled.h"
#include"ResourceTracker.h"
#include"IResource.h"
#include"GameBackground.h"


BackgroundImage::BackgroundImage(string path)
{
	m_y=m_x=m_x2=m_y2=0;
	
}
void BackgroundImage::init()
{
	m_receivedresources=Resourcetracker_INSTANCE->requestResource(string("newbg.png "),0);
	solid=true;
	
}
void BackgroundImage::loadResource()
{
	imager = static_cast<ImageResource *>(m_receivedresources.at(m_receivedresources.size()-1));
	m_tex=imager->m_bgtexture;
	m_backgroundsprite=new hgeSprite(*m_tex,0,0,12902,728);
	m_objectrect=new hgeRect(10,550,12902,550);
}
void BackgroundImage::render()
{
	
	
	m_backgroundsprite->Render(m_x,0);	
}
void BackgroundImage::update()
{

}
void BackgroundImage::handleInput(IEvent *event)
{
	if(dynamic_cast<KeyEvent*>(event))
	{	
	KeyEvent *key=dynamic_cast<KeyEvent*>(event);
	if(key->isKeyPressed(BUTTON_RIGHT))
	{if(m_x>-12000)
	m_x=m_x-HGE_INSTANCE->Timer_GetDelta()*100;
	if(key->isKeyPressed(BUTTON_CTRL))
						m_x=m_x+HGE_INSTANCE->Timer_GetDelta()*50;
	}
	
	if(key->isKeyPressed(BUTTON_LEFT))	
			m_x=m_x+HGE_INSTANCE->Timer_GetDelta()*50;
	}
}
void BackgroundImage::destroy()
{

}
BackgroundImage::BackgroundImage()
{
	m_y=m_x=m_x2=m_y2=0;
	/*ir=Resourcetracker_INSTANCE->getResource(string("background.png"));
	imager = static_cast<ImageResource *>(ir);
	*/
	m_font=new hgeFont("font1.fnt");

}

hgeRect* BackgroundImage::getObjectRect()
{
	return m_objectrect;
}