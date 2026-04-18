//DeliveryOrder.cpp
//Author:Mahmoud Taha Date[13/4/2026]

#include "DeliveryOrder.h"

DeliveryOrder::DeliveryOrder(int requestTimeStep, int sizeNumberOfDishesOfOrder,
	int orderPrice, int orderID,float distance,
	Scooter* pS, OrderTypeSec type):
	Order(requestTimeStep, sizeNumberOfDishesOfOrder, orderPrice, orderID)
{
	 setDistance(distance);
	 setScooter(pS);
	 m_orderType = type;
}

void DeliveryOrder::setDistance(float distance)
{
	m_disatance = (distance > 0) ? distance: -1;
}

void DeliveryOrder::setScooter(Scooter* pS)
{
	m_pScooter = pS;
}

float DeliveryOrder::getDistance() const
{
	return m_disatance;
}

Scooter* DeliveryOrder::getScooter() const
{
	return m_pScooter;
}

void DeliveryOrder::print(ostream& O)
{
	if (this->getScooter() != nullptr) {
			O << "[" << getOrderID() << ",S" << getScooter()->getScooterID() << "]";
		}
	else{
			O << getOrderID();
		}
	
}
