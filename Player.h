#pragma once
#include"ResourceTracker.h"
#include"GameAppFramework.h"
#include"IObject.h"
class Player:public IObject
{
private:
	//double _velX, _velY;

public:
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
	hgeRect *up,*down,*left,*right;
	void setCollision(bool );
	void setRect();
	int collisionflag;
	float getX();
	float getY();
	
	float x,y;
	hgeSprite *pl;
	Player();
	static float playerimageid;
	HTEXTURE m_playertexture[9];
	hgeRect *m_playerrect;
	DWORD *tex;
	ImageResource* imager;
	KeyEvent *m_k;
	bool PREVIOUSPRESS;
	int count;
	hgeRect* getobjRect();
	double _velX, _velY;




};