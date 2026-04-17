#pragma once


//Table.h
//Author:Mahmoud Taha Date[13/4/2026]

class Table
{
private:
	const int m_capacity;
	const int m_tableID;
	static int s_count;
	int m_freeSeats;

public:
	Table(int);
	~Table();
	Table()=default;
	~Table()=default;

	void setFreeSeats(int);
	int getCapacity()const;
	int getFreeSeats()const;
	int getTableID()const;

	void print()const;
	
};