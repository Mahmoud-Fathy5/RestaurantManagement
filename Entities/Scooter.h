#pragma once


//Scooter.h
//Author:Mahmoud Taha Date[13/4/2026]

#include <iostream>
using namespace std;

class Scooter
{
private:
	const int m_scooterID;
	static int s_count;
	int m_scooterSpeed;
	int m_maintenanceDuration;
	const int m_maintenanceOrdersCount;
	int m_ordersServedAfterLastMaintenanace;	
	int m_distaneCut;
public:
	Scooter(int,int,int);
	~Scooter()=default;

	int getScooterSpeed()const;
	int getMaintenanceSpeed()const;
	int getScooterID()const;

	void print()const;
	bool needsMaintenance()const;
	bool incrementOrdersServed();
	bool incrementDistaneCut(float);
	void resetOrdersServedAfterLastMaintenanace();

	friend ostream& operator << (ostream& outputStream, Scooter* pScooter);
};