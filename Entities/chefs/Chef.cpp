//Chef.cpp
//Author:Mahmoud Taha Date[13/4/2026]

#include<iostream>
#include "Chef.h"

Chef::Chef(int chefSpeed):m_chefID(s_count++),m_chefSpeed(chefSpeed)
{
}


int Chef::getChefSpeed() const
{
	return m_chefSpeed;
}

int Chef::getChefID() const
{
	return m_chefID;
}

int Chef::s_count = 0;

