#pragma once


//Table.h
//Author:Mahmoud Taha Date[13/4/2026]

class Table
{
private:
	int m_capacity;
public:
	Table()=default;
	~Table()=default;

	void setCapacity(int);
	int getCapacity()const;


};