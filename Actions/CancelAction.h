#pragma once

//CancelAction.h
//Author:Mohamed Medhat Saied Date[13/4/2026]


#include "action.h"

class CancelAction :public Action

{

private:

	int m_cancellationTimeStep;
	int m_IDForDeliveryOrders;

public:

	CancelAction();
	~CancelAction();

	void setCancellationTimeStep(int);
	void setIDForDeliveryOrders(int);
	int getIDForDeliveryOrders();
	int getCancellationTimeStep();

	void act();

};