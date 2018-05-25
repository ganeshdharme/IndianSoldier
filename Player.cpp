#include"precompiled.h"
#include"Player.h"
float Player::playerimageid=0;

void Player::init()
{
	_velY = 0;
	DWORD ptr=0;
	// m_playertexture = new HTEXTURE[10];
	 HTEXTURE m[10];
	string mystring;
	string path;
	for(int i=1;i<9;i++)
		{ 
			
			mystring = "walk@.png ";
		 string sr;
		  sr+= i+ '0';
		 mystring.replace(mystring.begin()+4,mystring.begin()+5,sr);
		 path=path+mystring;
		}
		 m_receivedresources= Resourcetracker_INSTANCE->requestResource(path,0);
}

float Player::getX()
{
	return x;
}
float Player::getY()
{
	return y;
}
void Player::loadResource()
{
	string mystring;
	for(int i=0;i<m_receivedresources.size();i++)
		{ 
	
		
		 imager = dynamic_cast<ImageResource *>(m_receivedresources[i]);
		 m_playertexture[i]=*imager->getTexture();
		}
	pl = new hgeSprite(m_playertexture[0],0,0,96,128);
	m_objectrect=new hgeRect(x,y,x+96,y+128);
	up=new hgeRect(x,y,x+96,y+10);
	down=new hgeRect(x,y+118,x+96,y+128);
	left=new hgeRect(x,y,x+10,y+118);
	right=new hgeRect(x+86,y,x+96,y+118);
}

void Player::render()
{
	
	pl->Render(x,y);
	setRect();
	
}
void Player::setCollision(bool flag)
{
	collisionflag=flag;
}
double gravity = 0.05;	

void Player::update()
{
	m_playerrect->Set(x, y, x+ 96, y + 128);
		/*if(y+128 > 550)
		{
			y = 550 - 128;
			_velY = 0;
		}*/
		if(collisionflag)
		{
			
		}
		else
		{
			y += _velY;
			_velY += gravity;
		
		}
		

}

void Player::destroy()
{

}

void Player::handleInput(IEvent* event)
{
	if( dynamic_cast<KeyEvent*>(event))
		{
			m_k=dynamic_cast<KeyEvent*>(event);
			if(m_k->isKeyPressed(BUTTON_RIGHT))
				{
						
				Player::playerimageid=Player::playerimageid+HGE_INSTANCE->Timer_GetDelta()*10;
				if(Player::playerimageid==7||Player::playerimageid>7)
						Player::playerimageid=0;
					if(x<400)
						x=x+HGE_INSTANCE->Timer_GetDelta()*50;
					if(m_k->isKeyPressed(BUTTON_CTRL&&x<400))
					{	x=x+HGE_INSTANCE->Timer_GetDelta()*100;
					Player::playerimageid=Player::playerimageid+HGE_INSTANCE->Timer_GetDelta()*10;}
						// y=420;
						count=floor(Player::playerimageid);
			pl->SetTexture(m_playertexture[count]);
			pl->SetFlip(false,false);
			setRect();
			
				}
			if(m_k->isKeyPressed(BUTTON_LEFT))
				{			
					if(Player::playerimageid==1||Player::playerimageid<1)
						Player::playerimageid=7;
					Player::playerimageid=Player::playerimageid-HGE_INSTANCE->Timer_GetDelta()*10;
					if(x>0)
						x=x-HGE_INSTANCE->Timer_GetDelta()*200;
						//y=420;
						count=floor(Player::playerimageid);
						pl->SetFlip(true,false);

						
					
			pl->SetTexture(m_playertexture[count]);
	setRect();
				}
				if(m_k->isKeyPressed(BUTTON_UP))
				{			
					_velY = -2.5;
					setCollision(false);
					setRect();
				}

				if(m_k->isKeyPressed(BUTTON_SPACE))
				{
					IObject *m_tempobj=new Bullet(x,y);
				m_tempobj->m_objectid=WorldMnagaer_getinstance->getObjectId();
				m_tempobj->init();
				m_tempobj->loadResource();
				WorldMnagaer_getinstance->addToActiveList(m_tempobj);
				//setCollision(true);
					//WorldMnagaer_getinstance->addToActiveList(bullet);
				}
			}
	

}
void Player::setRect()
{
	m_objectrect->Set(x,y,x+96,y+128);
	down->Set(x,y+118,x+96,y+128);
	left->Set(x,y,x+10,y+118);
	right->Set(x+86,y,x+96,y+118);
	up->Set(x,y,x+96,y+10);

}
Player::Player()
{
	collisionflag = false;
	x=100;y=10;
	m_playerrect = new hgeRect(x, y, x+96, y+128);
	m_k=NULL;
	PREVIOUSPRESS=false;
	tex=new HTEXTURE();
		
}

hgeRect* Player::getObjectRect()
{
	hgeRect *rect=new hgeRect[4];
	rect[0]=*up;
	rect[1]=*down;
	rect[2]=*left;
	rect[3]=*right;
	return rect;
}
hgeRect* Player::getobjRect()
{
	hgeRect *rect=new hgeRect[4];
	rect[0]=*down;
	rect[1]=*up;
	rect[2]=*left;
	rect[3]=*right;
	return rect;
}