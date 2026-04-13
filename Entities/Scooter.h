#pragma once


//Scooter.h
//Author:Mahmoud Taha Date[13/4/2026]

class Scooter
{
private:
	int m_scooterSpeed;
	int m_maintenanceDuration;
public:
	Scooter();
	~Scooter();

	void setScooterSpeed(int);
	void setMaintenanceSpeed(int);
	int getScooterSpeed()const;
	int getMaintenanceSpeed()const;

};