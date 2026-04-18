//Scooter.cpp
//Author:Mahmoud Taha Date[13/4/2026]

#include "Scooter.h"


Scooter::Scooter(int scooterSpeed,int maintenanceDuration,int maintenanceOrdersCount):
	m_scooterID(s_count++), m_maintenanceOrdersCount(maintenanceOrdersCount)
{
	m_scooterSpeed = (scooterSpeed >= 0) ? scooterSpeed: -1;
	m_maintenanceDuration = (maintenanceDuration >= 0) ? maintenanceDuration : -1;
	m_ordersServedAfterLastMaintenanace = 0;
	m_distaneCut = 0;
	
}

int Scooter::getScooterSpeed() const
{
	return m_scooterSpeed;
}

int Scooter::getMaintenanceSpeed() const
{
	return m_maintenanceDuration;
}

int Scooter::getScooterID() const
{
	return m_scooterID;
}






bool Scooter::needsMaintenance() const
{
	return (m_ordersServedAfterLastMaintenanace == m_maintenanceOrdersCount);
}

bool Scooter::incrementOrdersServed()
{
	if (m_ordersServedAfterLastMaintenanace < m_maintenanceOrdersCount) {
		m_ordersServedAfterLastMaintenanace++;
		return true;
	}
	else {
		return false;
	}
}

bool Scooter::incrementDistaneCut(float distance)
{
	if (distance>0) {
		m_distaneCut += distance;
		return true;
	}
	else {
		return false;
	}
	
}

void Scooter::resetOrdersServedAfterLastMaintenanace()
{
	m_ordersServedAfterLastMaintenanace = 0;
}


ostream& operator << (ostream& outputStream, Scooter* pScooter) {
	outputStream << pScooter->getScooterID();
	return outputStream;
};

int Scooter::s_count = 0;
