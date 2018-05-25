#pragma once

#include "Sprite.h"
#include "hgeFont.h"
#include "hge.h"

class Entity
{
protected:
	double m_x;
	double m_y;
	int m_width;
	int m_height;
	Sprite *m_sprite;
	hgeFont *m_font;

public:
	Entity(double, double);

	virtual	void loadSprite(HTEXTURE, int, int, int, int);
	virtual void update(HGE*);
	virtual void render(HGE*);

	void applyForce(double, double);
	double getX();
	double getY();
	int getWidth();
	int getHeight();
	hgeRect* getRectangle();

	void setFont(hgeFont*);

	~Entity(void);
};

