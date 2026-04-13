#pragma once

//Restaurant.h
//Author : Mohamed Medhat Saied Date[13/4/2026]


#include "../Actions/action.h"
#include "../DataStructures/LinkedQueue.h"
#include"../DataStructures/priQueue.h"
#include "../Entities/chefs/NormalChef.h"
#include "../Entities/chefs/SpecialChef.h"
#include"../Entities/Orders/Order.h"
#include"../Entities/Orders/DeliveryOrder.h"
#include"../Entities/Orders/DineInOrder.h"
#include"../Entities/Scooter.h"
#include"../Entities/Table.h"






class Restaurant
{
private:
	LinkedQueue<Action*>ActionsList;
	LinkedQueue<Order*>PendingDineInGrilledOrderList;
	LinkedQueue<Order*>PendingDineInNormalOrderList;
	LinkedQueue<Order*>PendingTakeAwayOrderList;
	LinkedQueue<Order*>PendingDeliveryDineInNormalOrderList;
	LinkedQueue<Order*>PendingDeliveryColdOrderList;

};