#include"precompiled.h"
#include"Enemy.h"

void Enemy::init()
{

	string path="rock.png ";
	m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
	enemy_img=dynamic_cast<ImageResource*>(m_receivedresources.at(0));
	solid=true;
}

void Enemy::render()
{
	if(m_x=3000)
	m_Enemysprite->Render(800,550-64);
}

void Enemy::update()
{
	
}

void Enemy::handleInput(IEvent *event)
{

}

hgeRect* Enemy::getObjectRect()
{
	return NULL;
}
Enemy::Enemy()
{

}
void Enemy::loadResource()
{
m_Enemysprite=new hgeSprite(*enemy_img->getTexture(),0,0,50,64);
m_enemyrect=new hgeRect(0,0,0,0);
}
void Enemy::destroy()
{

}