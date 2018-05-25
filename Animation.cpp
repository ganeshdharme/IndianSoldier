#include"precompiled.h"
#include"Animation.h"
Animation* Animation::m_instance = 0;
void Animation::PlayerAnimate()
{
	
}

void Animation::AnimateBackground()
{

}


Animation::Animation()
{
//rs=new DisplayManager();
}

Animation* Animation::getInstance()
{
	if(m_instance==NULL)
		m_instance=new Animation();
	return m_instance;
}
void Animation:: rebderBackground()
{
	/*rs->load_backgroundTexture();
	HTEXTURE *bg=rs->getbackgroundTexture();
	hgeSprite *hs=new hgeSprite(bg[0],0,0,3384,224);
	hs->Render(100,200);
	*/
}