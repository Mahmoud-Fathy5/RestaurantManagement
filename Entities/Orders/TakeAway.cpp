//TakeAway.cpp
//Author: Mahmoud Taha Date[13/4/2026]
#include "TakeAway.h"

TakeAway::TakeAway(int requestTimeStep, int sizeNumberOfDishesOfOrder, int orderPrice, int orderID):
	Order(requestTimeStep, sizeNumberOfDishesOfOrder, orderPrice, orderID)
{

}

void TakeAway::print(ostream& O)
{
	if (this->getChef() != nullptr) {
		O << "[" << this->getOrderID() << "," << this->getChef()->getChefID() << "]";
	}
	else {
		O << getOrderID();
	}
	
}


