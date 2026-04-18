#pragma once

// RequestAction.h
// Author:Mohamed Medhat Date[13/4/2026]



#include "action.h"
#include"../Entities/Orders/Order.h"
#include"../Entities/Orders/DeliveryOrder.h"
#include"../Entities/Orders/DineInOrder.h"
//#include"../System/Restaurant.h"

class RequestAction :public Action
{
private:

	OrderType m_orderType;
	int m_requestTimeStep;
	int m_ID;
	int m_sizeWhichIsNumberOfDishesOfOrder;
	float m_orderPrice;
	int m_numberOfSeatsForDineInOrders;
	float m_orderDurationForDineInOrders;
	bool m_canShareForDineInOrders;
	int m_distanceForDeliveryOrders;

public:

	RequestAction(ifstream&);
	~RequestAction()=default;

	
	int getRequestTimeStep();

	void act();
	void print(ostream&) override;

};