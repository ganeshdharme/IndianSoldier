#include "precompiled.h"
#include "StateIdentifier.h"

StateIdentifier* StateIdentifier::m_instance = 0;

StateIdentifier::StateIdentifier(void){
}

StateIdentifier* StateIdentifier::GetInstance(){
	if(m_instance == NULL)
		m_instance = new StateIdentifier();
	return m_instance;
}

StateIdentifier::~StateIdentifier(void){
}
