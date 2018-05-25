#pragma once

class Hurdles
{
public:
	void renderHurdles(HTEXTURE *,HGE *);
	void updatehurdles();
	void checkCollision();
	HTEXTURE  loadHurdles(HGE *);
	float m_x, m_y;
	
};