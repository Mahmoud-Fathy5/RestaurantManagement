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
		while (!temp.isEmpty()) {
			Order* o;
			int pri;
			temp.dequeue(o, pri);
			this->enqueue(o, pri);
		}	//End while
		return cancelledOrder;
	}	//End cancelOrder

	//void print() const
	//{
	//	priNode<Order*>* ptr = head;
	//	while (ptr)
	//	{
	//		int pri;
	//		Order* o = ptr->getItem(pri);
	//		cout << "[" << o->getOrderID() << "," <<o->getChef()->getChefID()<<"]";
	//		ptr = ptr->getNext();

	//	}
	//}

	
};