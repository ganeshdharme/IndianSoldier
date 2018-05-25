#include "precompiled.h"
#include "Broadcaster.h"


Broadcaster* Broadcaster::m_instance = 0;

Broadcaster::Broadcaster(void){
}

void Broadcaster:: registerForEvent(IListner* state){
	 m_listner.push_back(state);
	
}

void Broadcaster::UnregisterForEvent(IListner *state){
	
	vector<IListner*>::iterator i_traverser= m_listner.begin();
	while(i_traverser!= m_listner.end())
	{
		if(*i_traverser==state)
			break;
		i_traverser++;
	}
	 m_listner.erase(i_traverser);




}

void Broadcaster::onEventHappen(IEvent* state){

	
	for(int i=0;i< m_listner.size();i++)
	{
		 m_listner.at(i)->onNotify(state);

	}


}

Broadcaster* Broadcaster::GetInstance(){
	if(m_instance == NULL)
		m_instance = new Broadcaster();
	return m_instance;
}

Broadcaster::~Broadcaster(void){
}
