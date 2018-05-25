#include "precompiled.h"
#include "Entity.h"

Entity::Entity(double x, double y){
	this->m_x = x;
	this->m_y = y;
}

void Entity::loadSprite(HTEXTURE texture, int startX, int startY, int width, int height){
	m_sprite = new Sprite(texture, startX, startY, width, height);
	this->m_width = m_sprite->getWidth();
	this->m_height = m_sprite->getHeight();
}
void Entity::update(HGE* hge){
	m_sprite->Update(m_x, m_y);
}

void Entity::render(HGE* hge){
	m_sprite->render(m_x, m_y);
}

double Entity::getX(){ return this->m_x; }
double Entity::getY(){ return this->m_y; }
int Entity::getWidth(){ return this->m_width; }
int Entity::getHeight(){ return this->m_height; }
hgeRect* Entity::getRectangle(){ return m_sprite->getRectangle(); }

void Entity::setFont(hgeFont* font){ this->m_font = font; }

Entity::~Entity(void){
}
