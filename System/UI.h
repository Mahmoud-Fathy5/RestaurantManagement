#pragma once

//UI.h
//Author: Mahmoud Taha Date[13/4/2026]

#include "../DEFS.h"
#include<iostream>
#include<fstream>
//#include "../Actions/action.h"
#include"../Actions/RequestAction.h"
#include"../Actions/CancelAction.h"
//#include "../DataStructures/LinkedQueue.h"
//#include"../DataStructures/priQueue.h"
#include "../Entities/chefs/Chef.h"
//#include"../Entities/Orders/Order.h"
#include"../Entities/Orders/DeliveryOrder.h"
#include"../Entities/Orders/DineInOrder.h"
#include"../Entities/Scooter.h"
#include"../Entities/Table.h"
#include"../DataStructures/CookingOrders.h"
#include"../DataStructures/FitTables.h"
#include"../DataStructures/DerivedQueue.h"
#include"../DataStructures/ArrayStack.h"
#include"../Entities/Orders/TakeAway.h"
using namespace std;

class UI
{
private:
	Mode m_mode;
public:

	UI();
	~UI();
    string readInputFileName();
    void readOutputFileName(string);
	void readMode();
    void printScreen(int currentTimeStep,
        LinkedQueue<Action*>& actionsList,
        LinkedQueue<Order*>& pendingDineInGrilledOrderList,
        LinkedQueue<Order*>& pendingDineInNormalOrderList,
        LinkedQueue<Order*>& pendingTakeAwayOrderList,
        LinkedQueue<Order*>& pendingDeliveryDineInNormalOrderList,
        DerivedQueue& pendingDeliveryColdOrders,
        priQueue<Order*>&pendingDeliveryGrilledOrders,
        LinkedQueue<Chef*>& freeSpecialChef,
        LinkedQueue<Chef*>& freeNormalChef,
        ArrayStack<Order*>& cancelledOrders,
        ArrayStack<Order*>& finishedOrders,
        CookingOrders& cookingOrders,
        LinkedQueue<Order*>& readyTakeAwayOrder,
        DerivedQueue& readyDeliveryOrder,
        LinkedQueue<Order*>& readyDineInOrder,
        priQueue<Order*>& inServiceOrder,
        priQueue<Scooter*>& freeScooters,
        priQueue<Scooter*>& backScooters,
        LinkedQueue<Scooter*>& maintenanceScooter,
        FitTables& freeTables,
        FitTables& busySharable,
        FitTables& busyNoShare);

};