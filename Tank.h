#include"IEvent.h"
#include"ImageResource.h"
class Tank:IObject
{
	private:
	ImageResource *tank_img;
	hgeSprite *m_tanksprite;
	float m_x,m_y;
	hgeRect *m_tankrect;
public:
	Tank();
	void init()override;
	void render()override;
	void update()override;
	void handleInput(IEvent* event)override;
	void destroy()override;
	void loadResource()override;
	hgeRect *getObjectRect()override;
};