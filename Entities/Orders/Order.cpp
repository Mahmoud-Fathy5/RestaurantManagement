
//Order.cpp
//Author: Mahmoud Taha Date[13/4/2026]

#include "Order.h"
#include <iostream>


Order::Order(int requestTimeStep, int sizeNumberOfDishesOfOrder, int orderPrice, int orderID):m_orderID(orderID)
{
	setRequestTimeStep(requestTimeStep);
	setNumberOfDishes(sizeNumberOfDishesOfOrder);
	setOrderPrice(orderPrice);
}

void Order::setRequestTimeStep(int num)
{
	m_requestTimeStep = (num > 0) ? num : -1;
}

void Order::setAssignmentTimeStep(int num)
{
	m_assignmentTimeStep = (num > 0) ? num : -1;
}

void Order::setReadyTimeStep(int num)
{
	m_readyTimeStep = (num > 0) ? num : -1;
}

void Order::setServiceTimeStep(int num)
{
	m_ServiceTimeStep = (num > 0) ? num : -1;
}

void Order::setFinshTimeStep(int num)
{
	m_FinshTimeStep = (num > 0) ? num : -1;
}




void Order::setNumberOfDishes(int num)
{
	m_sizeNumberOfDishesOfOrder = (num >0)?  num : -1;
}

void Order::setOrderPrice(int num)
{
	m_orderPrice = (num > 0) ? num : -1;
}

void Order::setChef(Chef* pC)
{
	m_pChef = pC;
}

int Order::getRequestTimeStep() const
{
	return m_requestTimeStep;
}

int Order::getAssignmentTimeStep() const
{
	return m_assignmentTimeStep;
}

int Order::getReadyTimeStep() const
{
	return m_readyTimeStep;
}

int Order::getServiceTimeStep() const
{
	return m_ServiceTimeStep;
}

int Order::getFinshTimeStep() const
{
	return m_FinshTimeStep;
}

int Order::getNumberOfDishes() const
{
	return m_sizeNumberOfDishesOfOrder;
}

int Order::getOrderPrice() const
{
	return m_orderPrice;
}

Chef* Order::getChef() const
{
	return m_pChef;
}

int Order::getOrderID() const
{
	return m_orderID;
}

OrderTypeSec Order::getOrderType() const
{
	return m_orderType;
}




ostream& operator << (ostream& outputStream, Order* pOrder) {
	 pOrder->print(outputStream);
	 return outputStream;
};