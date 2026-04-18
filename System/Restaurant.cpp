#include "Restaurant.h"
#include <cstdlib>
#include <ctime>
using namespace std;

void Restaurant::readChef(ifstream&file)
{
	string nc,sc,snc,ssc;
	file >> nc>>sc>>snc>>ssc;
	for (int i = 0; i < stoi(nc); i++)
	{
		//add speed to chef constructor
		Chef* ch = new Chef(stoi(snc), CN);
		freeNormalChef.enqueue(ch);
	}
	for (int i = 0; i < stoi(sc); i++)
	{
		//add speed to chef constructor
		Chef* ch = new Chef(stoi(ssc), CS);
		freeSpecialChef.enqueue(ch);
	}

}

void Restaurant::readScooters(ifstream&file)
{
	string scooterNumber, scooterSpeed, mainOrders, mainDuration;
	file >> scooterNumber >> scooterSpeed >> mainOrders >> mainDuration;
	for (int i = 0; i < stoi(scooterNumber); i++)
	{
		//add speed to ScooterConstructor
		Scooter* sc = new Scooter(stoi(scooterSpeed), stoi(mainDuration), stoi(mainOrders));
		freeScooters.enqueue(sc,0);
	}
}

void Restaurant::readTables(ifstream&file)
{
	string numberOfTables;
	file >> numberOfTables;
	int i = 0;
	while(i<stoi(numberOfTables))
	{
		string noTables, noSeats;
		file >> noTables, noSeats;
		for (int j = 0; j < stoi(noTables); j++)
		{
			//add no of seats to the constructor of table
			Table* t = new Table(stoi(noSeats));
			freeTables.enqueue(t,-1*stoi(noSeats));
		}
		i = i + stoi(noTables);
	}

}

void Restaurant::readActions(ifstream&file)
{
	string noRequestActions;
	file >> noRequestActions;
	
	string actionType;
	while (file >> actionType)
	{
		if (actionType == "Q")
		{
			Action* rq = new RequestAction(file);
			actionsList.enqueue(rq);
		}
		else if (actionType == "X")
		{
			Action* cq = new CancelAction(file);
			actionsList.enqueue(cq);
		}
	}
	
}



Restaurant::Restaurant()
{
	userInterface = new UI();
}

Restaurant::~Restaurant()
{
	delete userInterface;
}

void Restaurant::readInput(ifstream&file)
{
	readChef(file);
	readScooters(file);
	readTables(file);
	readActions(file);
}


void Restaurant::generateRandomOrders()
{
    srand(time(0));

	int noOfNC = rand() % 20 + 5;
	for (int i = 0; i < noOfNC; i++)
	{
		Chef* NC = new Chef(0, CN);
		freeNormalChef.enqueue(NC);
	}
	int noOfSC = rand() % 20 + 5;
	for (int i = 0; i < noOfNC; i++)
	{
		Chef* SC = new Chef(0, CS);
		freeSpecialChef.enqueue(SC);
	}
	int noOfScooters = rand() % 20 + 5;
	for (int i = 0; i < noOfNC; i++)
	{
		Scooter* sc = new Scooter(1, 1, 1);
		freeScooters.enqueue(sc, 0);
	}
	int noOfTables = rand() % 20 + 5;
	for (int i = 0; i < noOfTables; i++)
	{
		Table* t = new Table(0);
		freeTables.enqueue(t, 0);
	}

    const int NUM_ORDERS = 500;

    for (int i = 0; i < NUM_ORDERS; i++)
    {
        int id = i + 1;

        // Random common attributes
        int TQ = rand() % 100 + 1;
        int size = rand() % 10 + 1;
        float price = (rand() % 2000) / 10.0f + 10; // 10 -> 210

        int category = rand() % 6;

        switch (category)
        {
        case ODN: // DineInNormal
        {
            int seats = rand() % 6 + 1;
            int duration = rand() % 120 + 10;
            bool share = rand() % 2;

            Order* o = new DineInOrder(TQ, size, price, id, seats, duration, share, NORMAL);
            pendingDineInNormalOrderList.enqueue(o);
            break;
        }

        case ODG: // DineInGrilled
        {
            int seats = rand() % 6 + 1;
            int duration = rand() % 120 + 10;
            bool share = rand() % 2;

            Order* o = new DineInOrder(TQ, size, price, id, seats, duration, share, GRILLED);
            pendingDineInGrilledOrderList.enqueue(o);
            break;
        }

        case OT: // Takeaway
        {
            Order* o = new TakeAway(TQ, size, price, id);
            pendingTakeAwayOrderList.enqueue(o);
            break;
        }

        case OVN: // DeliveryNormal
        {
            float dist = (rand() % 1000) / 10.0f;

            Order* o = new DeliveryOrder(TQ, size, price, id, dist,NORMAL);
            pendingDeliveryNormalOrderList.enqueue(o);
            break;
        }

        case OVG: // DeliveryGrilled
        {
            float dist = (rand() % 1000) / 10.0f;

            DeliveryOrder* o = new DeliveryOrder(TQ, size, price,id, dist, GRILLED);

            float priority = 0;
            pendingDeliveryGrilledOrders.enqueue(o, priority);

            break;
        }

        case OVC: // DeliveryCold
        {
            float dist = (rand() % 1000) / 10.0f;

            Order* o = new DeliveryOrder(TQ, size, price,id, dist, COLD);
            pendingDeliveryColdOrders.enqueue(o);
            break;
        }
        }
    }
}

void Restaurant::randomChefAssignment()
{
	srand(time(0));
	for (int i = 0; i < 30; i++)
	{
		if ((pendingDeliveryColdOrders.isEmpty()
			&& pendingDeliveryNormalOrderList.isEmpty()
			&& pendingDeliveryGrilledOrders.isEmpty()
			&& pendingDineInNormalOrderList.isEmpty()
			&& pendingTakeAwayOrderList.isEmpty()
			&& pendingDineInGrilledOrderList.isEmpty())
			||
			(freeNormalChef.isEmpty() && freeSpecialChef.isEmpty()))
		{
			break;
		}
		int order = rand() % 6;
		int chef = rand() % 2;
		Order* o = nullptr;
		Chef* c = nullptr;
		switch (order)
		{
		case ODN:
			if (!pendingDineInNormalOrderList.dequeue(o)) { continue; }
			chef ? (freeNormalChef.dequeue(c)) : (freeSpecialChef.dequeue(c));
			if (!c) {
				pendingDineInNormalOrderList.enqueue(o);
				continue;
			}
			o->setChef(c);
			cookingOrders.enqueue(o, 0);
			break;
		case ODG:
			if (!pendingDineInGrilledOrderList.dequeue(o)) { continue; }
			chef ? (freeNormalChef.dequeue(c)) : (freeSpecialChef.dequeue(c));
			if (!c) {
				pendingDineInGrilledOrderList.enqueue(o);
				continue;
			}
			o->setChef(c);
			cookingOrders.enqueue(o, 0);
			break;
		case OT:
			if (!pendingTakeAwayOrderList.dequeue(o)) { continue; }
			chef ? (freeNormalChef.dequeue(c)) : (freeSpecialChef.dequeue(c));
			if (!c) {
				pendingTakeAwayOrderList.enqueue(o);
				continue;
			}
			o->setChef(c);
			cookingOrders.enqueue(o, 0);
			break;
		case OVG:
			int pri;
			if (!pendingDeliveryGrilledOrders.dequeue(o, pri)) { continue; }
			chef ? (freeNormalChef.dequeue(c)) : (freeSpecialChef.dequeue(c));
			if (!c) {
				pendingDeliveryGrilledOrders.enqueue(o, 0);
				continue;
			}
			o->setChef(c);
			cookingOrders.enqueue(o, 0);
			break;
		case OVN:
			if (!pendingDeliveryNormalOrderList.dequeue(o)) { continue; };
			chef ? (freeNormalChef.dequeue(c)) : (freeSpecialChef.dequeue(c));
			if (!c) {
				pendingDeliveryNormalOrderList.enqueue(o);
				continue;
			}
			o->setChef(c);
			cookingOrders.enqueue(o, 0);
			break;
		case OVC:
			if (!pendingDeliveryColdOrders.dequeue(o)) { continue; };
			chef ? (freeNormalChef.dequeue(c)) : (freeSpecialChef.dequeue(c));
			if (!c) {
				pendingDeliveryColdOrders.enqueue(o);
				continue;
			}
			o->setChef(c);
			cookingOrders.enqueue(o, 0);
			break;
		}
	}
}

void Restaurant::randomFinishedCooking()
{
	srand(time(0));
	for (int i = 0; i < 15; i++)
	{
		if (cookingOrders.isEmpty()) { return; }
		int random = rand() % 100;
		if (random < 75) {
			Order* o = nullptr;
			int pri;
			cookingOrders.dequeue(o, pri);
			if (!o) { continue; }
			if (o->getChef()->getChefType() == CN) { freeNormalChef.enqueue(o->getChef()); }
			else { freeSpecialChef.enqueue(o->getChef()); }
			o->setChef(nullptr);
			if (dynamic_cast<DineInOrder*>(o)) { readyDineInOrder.enqueue(o); }
			if (dynamic_cast<DeliveryOrder*>(o)) { readyDeliveryOrder.enqueue(o); }
			if (dynamic_cast<TakeAway*>(o)) { readyTakeAwayOrder.enqueue(o); }
		}
	}
}

void Restaurant::randomServiceAssignment()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		if (readyDeliveryOrder.isEmpty() && readyDineInOrder.isEmpty() && readyTakeAwayOrder.isEmpty()) { return; }
		int random = rand() % 3;
		Order* o = nullptr;
		switch (random)
		{
		
		case 0: //OD
			
			readyDineInOrder.dequeue(o);
			if (o) {
				DineInOrder* od = (DineInOrder*)o;
				Table* t = nullptr;
				int pri;
				freeTables.dequeue(t, pri);
				if (!t) { continue; }
				inServiceOrder.enqueue(o, 0);
				od->setTable(t);
				if (od->getCanShare()) { busySharable.enqueue(t, 0); }
				else { busyNoShare.enqueue(t,0); }
			}
			break;
		case 1: //OV
			
			readyDeliveryOrder.dequeue(o);
			if (o) {
				DeliveryOrder* ov = (DeliveryOrder*)o;
				Scooter* sc = nullptr;
				int pri;
				freeScooters.dequeue(sc,pri);
				if (!sc) { continue; }
				inServiceOrder.enqueue(o, 0);
				ov->setScooter(sc);
			}
			break;
		case 2:
			
			readyTakeAwayOrder.dequeue(o);
			if (o) {
				finishedOrders.push(o);
			}
			break;
		}
	}
}

void Restaurant::randomCancelOrder()
{
	srand(time(0));
	int random = rand() % 500 + 1;
	Order* cancelled = pendingDeliveryColdOrders.cancelOrder(random);
	if (cancelled) {
		cancelledOrders.push(cancelled);
	}
	random = rand() % 500;
	cancelled = readyDeliveryOrder.cancelOrder(random);
	if (cancelled) {
		cancelledOrders.push(cancelled);
	}
	random = rand() % 500;
	cancelled = cookingOrders.cancelOrder(random);

	if (cancelled) {
		Chef* c= cancelled->getChef();
		cancelled->setChef(nullptr);
		if (c->getChefType() == CN) { freeNormalChef.enqueue(c); }
		else { freeSpecialChef.enqueue(c); }
		cancelledOrders.push(cancelled);
	}
}

void Restaurant::randomFinishingOrder()
{
	srand(time(0));
	int random = rand() % 100;
	if (random < 25) {
		Order* o = nullptr;
		int pri;
		inServiceOrder.dequeue(o, pri);
		if (!o) { return; }
		if (dynamic_cast<DeliveryOrder*>(o))
		{
			finishedOrders.push(o);
			DeliveryOrder* ov = (DeliveryOrder*)o;
			backScooters.enqueue(ov->getScooter(),0);
			ov->setScooter(nullptr);
		}
		if (dynamic_cast<DineInOrder*>(o))
		{
			finishedOrders.push(o);
			DineInOrder* od = (DineInOrder*)o;
			Table* t = od->getTable();
			if (!t) { return; }
			freeTables.enqueue(t, 0);
			od->setTable(nullptr);
		}
	}
}

void Restaurant::randomScooters()
{
	srand(time(0));
	int random = rand() % 100;
	if (random < 50)
	{
		Scooter* sc = nullptr;
		int pri;
		backScooters.dequeue(sc, pri);
		if (sc) {
			random = rand() % 2;
			if (random) { freeScooters.enqueue(sc, 0); }
			else { maintenanceScooter.enqueue(sc); }
		}
	}
	random = rand() % 100;
	if (random < 50)
	{
		Scooter* sc = nullptr;
		maintenanceScooter.dequeue(sc);
		if (sc) { freeScooters.enqueue(sc, 0); }
	}
}

void Restaurant::simulate()
{
	int currnet_Time_Step = 0;
	generateRandomOrders();
	while ((finishedOrders.getCount() + cancelledOrders.getCount()) != 500) {
		userInterface->printScreen(currnet_Time_Step,
			actionsList,
			pendingDineInGrilledOrderList,
			pendingDineInNormalOrderList,
			pendingTakeAwayOrderList,
			pendingDeliveryNormalOrderList,
			pendingDeliveryColdOrders,
			pendingDeliveryGrilledOrders,
			freeSpecialChef,
			freeNormalChef,
			cancelledOrders,
			finishedOrders,
			cookingOrders,
			readyTakeAwayOrder,
			readyDeliveryOrder,
			readyDineInOrder,
			inServiceOrder,
			freeScooters,
			backScooters,
			maintenanceScooter,
			freeTables,
			busySharable,
			busyNoShare);
		system("cls");

		randomChefAssignment();
		randomFinishedCooking();
		randomServiceAssignment();
		randomCancelOrder();
		randomFinishingOrder();
		randomScooters();
		currnet_Time_Step++;

	};
		
}




