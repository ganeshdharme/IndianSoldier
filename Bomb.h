#include"IEvent.h"
#include"ImageResource.h"
class Bomb:public IObject
{

	private:
	ImageResource *bomb_img;
	hgeSprite *m_bombsprite;
	float m_x,m_y;
	hgeRect *m_bombrect;
public:
	Bomb();
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
};