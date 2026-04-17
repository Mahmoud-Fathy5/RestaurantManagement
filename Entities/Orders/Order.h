#pragma once


//Order.h
//Author: Mahmoud Taha Date[13/4/2026]

#include "../chefs/Chef.h"
#include "../../DEFS.h"

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
	OrderTypeSec m_orderType;
public:
	Order(int, int, int, int );

	void setRequestTimeStep(int);
	void setNumberOfDishes(int);
	void setOrderPrice(int);
	void setChef(Chef*);
	int getRequestTimeStep()const;
	int getNumberOfDishes()const;
	int getOrderPrice()const;
	Chef* getChef()const;
	int getOrderID()const;
	OrderTypeSec getOrderType()const;

	virtual void print()const=0;
	

};

