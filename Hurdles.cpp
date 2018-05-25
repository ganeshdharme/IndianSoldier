#include"precompiled.h"
#include"Hurdles.h"
void Hurdles::renderHurdles(HTEXTURE *hrhurdletex,HGE *hge)
{
	hgeSprite walkcharacters1(hge->Texture_Load("hurdles.png"), 0, 0, 73, 117);
	//hgeRect rec(100, 350, 200, 450);
//	hurdlerect->Set(135 + x, 375, 200, 425);
	walkcharacters1.Render(135+m_x, 360);
}
HTEXTURE Hurdles::loadHurdles(HGE *hge)
{
	HTEXTURE hurdlesimg= hge->Texture_Load("hurdles.png");
//	hurdlerect = new hgeRect(135 + x, 375, 200, 425);
	//hurdlerect->Clear();
	return hurdlesimg;
}