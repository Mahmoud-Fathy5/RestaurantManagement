#pragma once


//DineInOrder.h
//Author: Mahmoud Taha Date[13/4/2026]

#include"Order.h"


class DineInOrder :public Order
{
private:
	int m_numberOfSeats;
	int m_orderDuration;
	bool m_canShare;
public:
	/*DineInOrder();
	~DineInOrder();*/

	void setNumberOfSeats(int);
	void setOrderDuration(int);
	void setCanShare(bool);
	int getNumberOfSeats()const;
	int getOrderDuration()const;
	bool getCanShare()const;


};