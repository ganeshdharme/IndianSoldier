#include "precompiled.h"
#include "Cursor.h"

Cursor::Cursor(double x, double y, Input* input) : Entity(x, y){
	this->m_input = input;
}

void Cursor::update(HGE* hge){
	m_x = m_input->getMouseX();
	m_y = m_input->getMouseY();
}

void Cursor::render(HGE* hge){
	m_sprite->render(m_x, m_y);
}

Cursor::~Cursor(void){
}
