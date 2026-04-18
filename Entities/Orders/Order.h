#pragma once


//Order.h
//Author: Mahmoud Taha Date[13/4/2026]

#include "../chefs/Chef.h"
#include "../../DEFS.h"
#include <ostream>

using namespace std;

class Order
{
private:
	int m_requestTimeStep;
	int m_assignmentTimeStep;
	int m_readyTimeStep;
	int m_ServiceTimeStep;
	int m_FinshTimeStep;
	int m_sizeNumberOfDishesOfOrder;
	int m_orderPrice;
	Chef* m_pChef;
	const int m_orderID;
protected:
	OrderTypeSec m_orderType;
public:
	Order(int, int, int, int );

	void setRequestTimeStep(int);
	void setAssignmentTimeStep(int);
	void setReadyTimeStep(int);
	void setServiceTimeStep(int);
	void setFinshTimeStep(int);
	void setNumberOfDishes(int);
	void setOrderPrice(int);
	void setChef(Chef*);
	int getRequestTimeStep()const;
	int getAssignmentTimeStep()const;
	int getReadyTimeStep()const;
	int getServiceTimeStep()const;
	int getFinshTimeStep()const;
	int getNumberOfDishes()const;
	int getOrderPrice()const;
	Chef* getChef()const;
	int getOrderID()const;
	OrderTypeSec getOrderType()const;

	virtual void print(ostream&)=0;

	friend ostream& operator << (ostream& outputStream, Order* pOrder) {
		pOrder->print(outputStream);
		return outputStream;
	};

};

