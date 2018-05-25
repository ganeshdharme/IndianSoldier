#include "precompiled.h"
#include "DisplayManager.h"


DisplayManager::DisplayManager(void)
{
	m_backgroundtexture=new HTEXTURE();

}

DisplayManager::~DisplayManager(void)
{
}


HTEXTURE * DisplayManager::getbackgroundTexture()
{

	return m_backgroundtexture;
}

HTEXTURE * DisplayManager::getCloudTexture()
{
	return m_cloudstexture;
}

HTEXTURE * DisplayManager::getHurdlesTexture()
{
	return m_hurdles;
}

HTEXTURE * DisplayManager::getPlayerTexture()
{
	return m_player;
}

void DisplayManager::load_backgroundTexture()
{
 HTEXTURE m_backgroundtexture=HGE_INSTANCE->Texture_Load("level1.png");
 this->m_backgroundtexture=&m_backgroundtexture;
}

void DisplayManager::load_CloudTexture()
{
}

void DisplayManager::load_HurdlesTexture()
{
}


void DisplayManager::load_PlayerTexture()
{
			int counter=0;
			m_player[counter++]= HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk1.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk2.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk3.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk4.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk5.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk6.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk7.png");
			m_player[counter++] = HGE_INSTANCE->Texture_Load("D:\\Game characters\\Walk\\walk8.png");
	}
