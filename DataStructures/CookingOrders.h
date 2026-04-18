#pragma once
#include "priQueue.h"
#include "../Entities/Orders/Order.h"

//CookingOrders.h
//Author: Mahmoud Fathy  Date:[17/4/2026] 

class CookingOrders : public priQueue<Order*>
{
public:
	Order* cancelOrder(int ID)
	{
		Order* cancelledOrder = nullptr;
		CookingOrders temp;
		while (!this->isEmpty()) {
			Order* o;
			int pri;
			this->dequeue(o, pri);
			if (!(o->getOrderID() == ID)) {
				temp.enqueue(o, pri);
			}
			else {
				cancelledOrder = o;
			}	//End else
		}	//End while
		return cancelledOrder;
	}	//End cancelOrder
};