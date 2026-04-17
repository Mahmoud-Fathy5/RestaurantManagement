#include "Restaurant.h"

void Restaurant::readChef(ifstream&file)
{
	string nc,sc,snc,ssc;
	file >> nc>>sc>>snc>>ssc;
	for (int i = 0; i < stoi(nc); i++)
	{
		//add speed to chef constructor
		NormalChef* ch = new NormalChef();
		freeNormalChef.enqueue(ch);
	}
	for (int i = 0; i < stoi(sc); i++)
	{
		//add speed to chef constructor
		SpecialChef* ch = new SpecialChef();
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
		Scooter* sc = new Scooter;
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
			Table* t = new Table;
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
	
}

void Restaurant::readInput(ifstream&file)
{
	readChef(file);
	readScooters(file);
	readTables(file);
	readActions(file);
}
