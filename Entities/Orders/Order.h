#pragma once


//Order.h
//Author: Mahmoud Taha Date[13/4/2026]

#include "../chefs/Chef.h"
#include "../../Definitions.h"

using namespace std;

class Order
{
private:
	int m_requestTimeStep;
	int m_sizeNumberOfDishesOfOrder;
	int m_orderPrice;
	Chef* m_pChef;
	const int m_orderID;
protected:
	OrderType m_orderType;
public:
	Order(int, int, int, int );
	virtual ~Order();

	void setRequestTimeStep(int);
	void setNumberOfDishes(int);
	void setOrderPrice(int);
	void setChef(Chef*);
	int getRequestTimeStep()const;
	int getNumberOfDishes()const;
	int getOrderPrice()const;
	Chef* getChef()const;
	int getOrderID()const;
	OrderType getOrderType()const;

	virtual void print()const=0;
	

};

