#pragma once

//Restaurant.h
//Author : Mohamed Medhat Saied Date[13/4/2026]

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
#include"UI.h"





class Restaurant
{
private:
	/*int m_normalChefNumber;
	int m_specialChefNumber;
	int m_normalChefSpeed;
	int m_specialChefSpeed;
	int m_noOfScooters;
	int m_scooterSpeed;
	int m_MainDuration;
	int m_MainOrders;
	int m_TablesNo;
	int numberRequests;*/

	void readChef(ifstream&);
	void readScooters(ifstream&);
	void readTables(ifstream&);
	void readActions(ifstream&);
	
	UI* userInterface;
	LinkedQueue<Action*>actionsList;
	LinkedQueue<Order*>pendingDineInGrilledOrderList;
	LinkedQueue<Order*>pendingDineInNormalOrderList;
	LinkedQueue<Order*>pendingTakeAwayOrderList;
	LinkedQueue<Order*>pendingDeliveryNormalOrderList;
	DerivedQueue pendingDeliveryColdOrders;
	priQueue<Order*>pendingDeliveryGrilledOrders;
	LinkedQueue<Chef*>freeSpecialChef;
	LinkedQueue<Chef*>freeNormalChef;
	ArrayStack<Order*>cancelledOrders;
	ArrayStack<Order*>finishedOrders;
	CookingOrders cookingOrders;
	LinkedQueue<Order*>readyTakeAwayOrder;
	DerivedQueue readyDeliveryOrder;
	LinkedQueue<Order*>readyDineInOrder;
	priQueue<Order*>inServiceOrder;
	priQueue<Scooter*>freeScooters;
	priQueue<Scooter*>backScooters;
	LinkedQueue<Scooter*>maintenanceScooter;
	FitTables freeTables;
	FitTables busySharable;
	FitTables busyNoShare;



public:
	Restaurant();
	~Restaurant();

	/*void setNormalChefSpeed(int);
	void setSpecialChefSpeed(int);
	void setNormalChefNumber(int);
	void setSpecialChefNumber(int);
	void setNumberScooters(int);
	void setScootersSpeed(int);
	void setMaintenanceDuration(int);
	void setMainOrders(int);
	void setNumberTables(int);
	void setNumberRequests(int);*/

	void readInput(ifstream&);

	/*void addAction(Action*);
	void addPendingGrilled(Order*);
	void addPendingDineIn(Order*);
	void addPendingTakeAway(Order*);
	void addPendingDeliveryDineIn(Order*);
	void addPendingDeliveryCold(Order*);
	void addPendingDeliveryGrilled(Order*);
	void addSpecialChef(SpecialChef*);
	void addNormalChef(NormalChef*);
	void addCancelledOrders(Order*);
	void addFinishedOrders(Order*);
	void addCookingOrders(Order*);
	void addReadyTakeAwayOrders(Order*);
	void addReadyDeliveryOrders(Order*);
	void addReadyDineInOrders(Order*);
	void addInServiceOrder(Order*);
	void addFreeScooter(Scooter*);
	void addBackScooter(Scooter*);
	void addMaintenanceScooter(Scooter*);
	void addFreeTables(Table*);
	void addBusySharableTables(Table*);
	void addBusyNoShareTables(Table*);*/


	void generateRandomOrders();
	void randomChefAssignment();
	void randomFinishedCooking();
	void randomServiceAssignment();
	void randomCancelOrder();
	void randomFinishingOrder();
	void randomScooters();
	void simulate();

};