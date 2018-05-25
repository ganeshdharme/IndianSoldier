#include "precompiled.h"
#include "Menu.h"
#include"StatechangeEvent.h"

Menu::Menu(void)
{
	m_font = new hgeFont("font1.fnt");
	m_play_sprite = new Entity(400, 100);
	m_play_sprite->loadSprite(HGE_INSTANCE->Texture_Load("start.png"), 0, 0, 77, 32);
	m_options = new Entity(400, 200);
	m_options->loadSprite(HGE_INSTANCE->Texture_Load("options.png"), 0, 0, 78, 32);
	m_exit = new Entity(400, 300);
	m_exit->loadSprite(HGE_INSTANCE->Texture_Load("exit.png"), 0, 0, 100, 32);
	m_cursor = new Sprite(HGE_INSTANCE->Texture_Load("cursor.png"), 0, 0, 50, 50);
}

void Menu::Update()
{

	m_play_sprite->update(HGE_INSTANCE);
	float mouseX, mouseY;
	HGE_INSTANCE->Input_GetMousePos(&mouseX, &mouseY);
	if(HGE_INSTANCE->Input_GetKeyState(HGEK_LBUTTON))
	{
		if(m_play_sprite->getRectangle()->TestPoint(mouseX, mouseY))
		{
//			exit(1);
			StateChangeEvent eve;
			eve.mcurrentstate=eve.RUNNING;
			BROADCASTER->onEventHappen(&eve);
		}

	}
}

void Menu::Render(){
	float mx, my;
	HGE_INSTANCE->Input_GetMousePos(&mx, &my);
	 m_font->printf(400, 100, HGETEXT_MIDDLE, "MENU");
	m_play_sprite->render(HGE_INSTANCE);
	m_options->render(HGE_INSTANCE);
	m_exit->render(HGE_INSTANCE);
	m_cursor->render(mx, my);
}

Menu::~Menu(void){
}

void Menu::handleInput(IEvent *event)
{
	if( m_keyboardinstance = dynamic_cast<KeyEvent*>(event))
	{
			if(m_keyboardinstance->isKeyPressed(BUTTON_SPACE))
			{
				StateChangeEvent eve;
				eve.mcurrentstate=eve.RUNNING;
				BROADCASTER->onEventHappen(&eve);
	
			}

	}
}
string  Menu::getResourcevector()
{
	return path;
}
void Menu::loadResource()
{

}