#pragma once
#include "LinkedQueue.h"
#include "../Entities/Orders/Order.h"

//DerivedQueue.h
//Author: Mahmoud Fathy	 Date:[17/4/2026]

class DerivedQueue : public LinkedQueue<Order*>
{
public:
	Order* cancelOrder(int ID)
	{
		Order* cancelledOrder = nullptr;
		DerivedQueue temp;
		while (!this->isEmpty()) {
			Order* o;
			this->dequeue(o);
			if (!(o->getOrderID() == ID)) {
				temp.enqueue(o);
			}
			else {
				cancelledOrder = o;
			}	//End else
		}	//End while
		while (!temp.isEmpty())
		{
			Order* o;
			temp.dequeue(o);
			this->enqueue(o);
		}
		return cancelledOrder;
	}	//End cancelOrder
};