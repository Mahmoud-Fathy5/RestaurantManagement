#pragma once

//CancelAction.h
//Author:Mohamed Medhat Saied Date[13/4/2026]


#include "action.h"

class CancelAction :public Action

{

private:

	int m_cancellationTimeStep;
	int m_ID;

public:

	CancelAction(ifstream&);
	~CancelAction()=default;

	
	int getIDForDeliveryOrders();

	void act();

};