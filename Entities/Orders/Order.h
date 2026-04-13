#pragma once


//Order.h
//Author: Mahmoud Taha Date[13/4/2026]


class Order
{
private:
	int m_requestTimeStep;
	int m_sizeNumberOfDishesOfOrder;
	int m_OrderPrice;
	//string m_OrderType
public:
	Order();
	~Order();

	void setRequestTimeStep(int);
	void setNumberOfDishes(int);
	void setOrderPrice(int);
	int getRequestTimeStep()const;
	int getNumberOfDishes()const;
	int getOrderPrice()const;


};