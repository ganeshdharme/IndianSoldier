#pragma once
#include"precompiled.h"
class DisplayManager
{
	
	HTEXTURE *m_backgroundtexture;
	HTEXTURE m_cloudstexture[20];
	HTEXTURE m_player[20];
	//HTEXTURE i_
	HTEXTURE m_hurdles[20];
	
public:
	DisplayManager(void);
	~DisplayManager(void);
	void load_backgroundTexture();
	void load_PlayerTexture();
	void load_HurdlesTexture();
	void load_CloudTexture();
	HTEXTURE *getbackgroundTexture();
	HTEXTURE *getPlayerTexture();
	HTEXTURE *getHurdlesTexture();
	HTEXTURE *getCloudTexture();


};

