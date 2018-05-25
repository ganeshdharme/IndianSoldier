#pragma once

#include "hgeSprite.h"
#include "hge.h"

class Sprite
{
private:
	double m_x, m_y;
	double m_width, m_height;
	hgeSprite *m_sprite;
	hgeRect* m_rectangle;

public:
	Sprite(HTEXTURE, int, int, int , int);
	Sprite(int, int, int);

	void Update(double, double);
	void render(double, double);
	void renderStretch(double, double, double, double);
	void renderEx(double, double, double, double, double);
	void set(double, double);
	int getWidth();
	int getHeight();
	hgeRect* getRectangle();

	~Sprite(void);
};

