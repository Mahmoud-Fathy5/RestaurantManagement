//Chef.cpp
//Author:Mahmoud Taha Date[13/4/2026]

#include "Table.h"
#include <ostream>
using namespace std;

Table::Table(int capacity) :m_capacity(capacity),m_tableID(s_count++)
{
	setFreeSeats(capacity);
}





void Table::setFreeSeats(int freeSeats)
{
	m_freeSeats = (freeSeats <= m_capacity) ? freeSeats:-1; //-1 means error cannot fit
}


int Table::getCapacity() const
{
	return m_capacity;
}

int Table::getFreeSeats() const
{
	return m_freeSeats;
}

int Table::getTableID() const
{
	return m_tableID;
}






void Table::print() const
{
}

ostream& operator << (ostream& outputStream, Table* pTable) {
	if (pTable->getFreeSeats() >0) {
		outputStream << "[T" << pTable->getTableID() << "," << pTable->getCapacity() << "," << pTable->getFreeSeats() << "]";
	}
	
	return outputStream;
};


int Table::s_count = 0;
