#pragma once

class Animation
{
	
	Animation();
	 static Animation *m_instance;
public:
	static Animation* getInstance();
	void PlayerAnimate();
	
	void AnimateBackground();
	void rebderBackground();
	~Animation();
};