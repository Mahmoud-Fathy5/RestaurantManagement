#pragma once

//UI.h
//Author: Mahmoud Taha Date[13/4/2026]

#include "../DEFS.h"
#include <iostream>
#include "../System/Restaurant.h"
using namespace std;

class UI
{
private:
	Mode m_mode;
public:

	UI();
	~UI();

	void readMode();
    void printScreen(int currentTimeStep,
        LinkedQueue<Action*>* actionsList,
        LinkedQueue<Order*>* pendingDineInGrilledOrderList,
        LinkedQueue<Order*>* pendingDineInNormalOrderList,
        LinkedQueue<Order*>* pendingTakeAwayOrderList,
        LinkedQueue<Order*>* pendingDeliveryDineInNormalOrderList,
        DerivedQueue* pendingDeliveryColdOrders,
        priQueue<Order*>*pendingDeliveryGrilledOrders,
        LinkedQueue<Chef*>* freeSpecialChef,
        LinkedQueue<Chef*>* freeNormalChef,
        ArrayStack<Order*>* cancelledOrders,
        ArrayStack<Order*>* finishedOrders,
        CookingOrders* cookingOrders,
        LinkedQueue<Order*>* readyTakeAwayOrder,
        DerivedQueue* readyDeliveryOrder,
        LinkedQueue<Order*>* readyDineInOrder,
        priQueue<Order*>* inServiceOrder,
        priQueue<Scooter*>* freeScooters,
        priQueue<Scooter*>* backScooters,
        LinkedQueue<Scooter*>* maintenanceScooter,
        FitTables* freeTables,
        FitTables* busySharable,
        FitTables* busyNoShare);

};