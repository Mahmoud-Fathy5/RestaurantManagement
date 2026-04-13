#pragma once


//DeliveryOrder.h
//Author:Mahmoud Taha Date[13/4/2026]


#include "Order.h"

class DeliveryOrder :public Order
{
private:
	int Disatance;
public:
	DeliveryOrder();
	~DeliveryOrder();

	void setDistance(int);
	int getDistance()const;

};