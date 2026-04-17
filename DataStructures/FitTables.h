#pragma once
#include "priQueue.h"
#include "../Entities/Table.h"

//FitTables.h
//Author: Mahmoud Fathy  Date: [17/4/2026]

class FitTables : public priQueue<Table*>
{
	Table* getBest(int neededSeats)		//The Lowest Table has the most pri -> pri = -number of available seats
	{
		Table* bestFit = nullptr;
		FitTables temp;
		while (!this->isEmpty()) {
			Table* t;
			int pri;
			this->dequeue(t, pri);
			if (!( - pri > neededSeats)) {
				temp.enqueue(t, pri);
			}
			else {
				bestFit = t;
			}	//End else
		}	//End while
		return bestFit;
	}	//End getBest
};