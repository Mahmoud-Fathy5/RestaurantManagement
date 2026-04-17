#pragma once


//DeliveryOrder.h
//Author:Mahmoud Taha Date[13/4/2026]


#include "Order.h"
#include "../Scooter.h"

class DeliveryOrder :public Order
{
private:
	float m_disatance;
	Scooter* m_pScooter;
public:
	DeliveryOrder(int, int, int, int,float,Scooter*);
	~DeliveryOrder();

	void setDistance(float);
	void setScooter(Scooter*);
	float getDistance()const;
	Scooter* getScooter()const;

};