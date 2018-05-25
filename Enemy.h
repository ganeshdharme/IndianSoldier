#include"IObject.h"
#include"IEvent.h"
class Enemy:public IObject
{
private:
	ImageResource *enemy_img;
	hgeSprite *m_Enemysprite;
	float m_x,m_y;
	hgeRect *m_enemyrect;
public:
	Enemy();
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
};