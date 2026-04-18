//DineInOrder.h
//Author: Mahmoud Taha Date[13/4/2026]


#include "DineInOrder.h"

DineInOrder::DineInOrder(int requestTimeStep, int sizeNumberOfDishesOfOrder, int orderPrice, int orderID,
	int numberOfSeats, int orderDuration,bool canshare ,OrderTypeSec type):
	Order(requestTimeStep, sizeNumberOfDishesOfOrder, orderPrice, orderID)
{
	setNumberOfSeats(numberOfSeats);
	setOrderDuration(orderDuration);
	m_orderType = type; // will do exception handling to Cold
	m_canShare = canshare;
}

void DineInOrder::setNumberOfSeats(int numberOfSeats)
{
	m_numberOfSeats = (numberOfSeats > 0) ? numberOfSeats : -1;
}

void DineInOrder::setOrderDuration(float duration)
{
	m_orderDuration = (duration > 0) ?  duration: -1;
}

void DineInOrder::setCanShare(bool canShare)
{
	m_canShare = canShare;
}

void DineInOrder::setTable(Table* pT)
{
	m_pTable = pT;
}

int DineInOrder::getNumberOfSeats() const
{
	return m_numberOfSeats;
}

float DineInOrder::getOrderDuration() const
{
	return m_orderDuration;
}

bool DineInOrder::getCanShare() const
{
	return m_canShare;
}

Table* DineInOrder::getTable() const
{
	return m_pTable;
}

void DineInOrder::print(ostream& O) 
{
	if (this->getChef() != nullptr) {
		O << "[" << this->getOrderID() << "," << this->getChef()->getChefID() << "]";
	}
	else if (this->getTable() !=nullptr) {
		O << "[" << getOrderID()<<",T"<<getTable()->getTableID() << "]";
	}
	else{
		O << getOrderID();
	}
}
