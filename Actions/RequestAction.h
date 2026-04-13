#pragma once

// RequestAction.h
// Author:Mohamed Medhat Date[13/4/2026]



#include "action.h"

class RequestAction :public Action
{
private:

	string m_orderType;
	int m_requestTimeStep;
	int ID;
	int m_sizeWhichIsNumberOfDishesOfOrder;
	float orderPrice;
	int m_numberOfSeatsForDineInOrders;
	float m_orderDurationForDineInOrders;
	bool m_canShareForDineInOrders;
	int m_distanceForDeliveryOrders;

public:

	RequestAction();
	~RequestAction();

	void setRequestTimeStep(int);
	void setNumberOfDishesOfOrder(int);
	void setOrderPrice(float);
	void setNumberOfSeatsForDineInOrders(int);
	void setOrderDurationForDineInOrders(int);
	void setCanShareForDineInOrders(bool);
	void setDistanceForDeliveryOrders(int);
	string getOrderType();
	int getRequestTimeStep();
	int getNumberOfDishesOfOrder();
	float getOrderPrice();
	int getNumberOfSeatsForDineInOrders();
	int getOrderDurationForDineInOrders();
	bool getCanShareForDineInOrders();
	int getDistanceForDeliveryOrders();

	void act();

};