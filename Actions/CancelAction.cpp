#pragma

//CancelAction.cpp
//Author : Mohamed Medhat  Date[17/4/2026]

#include "CancelAction.h"

CancelAction::CancelAction(ifstream&file)
{
	string t;
	file >> t;
	m_cancellationTimeStep = stoi(t);
	file >> t;
	m_ID = stoi(t);
}




int CancelAction::getIDForDeliveryOrders()
{
	return m_ID;
}
void CancelAction::act()
{

}

void CancelAction::print(ostream&)
{
	cout << "(X,"<<m_cancellationTimeStep<<","<<m_ID << ")";
}


