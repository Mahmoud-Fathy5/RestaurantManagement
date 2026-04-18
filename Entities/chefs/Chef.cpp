//Chef.cpp
//Author:Mahmoud Taha Date[13/4/2026]

#include<iostream>
#include "Chef.h"

Chef::Chef(int chefSpeed, ChefType ct):m_chefID(s_count++),m_chefSpeed(chefSpeed),m_chefType(ct)
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

ChefType Chef::getChefType()
{
	return m_chefType;
}

int Chef::s_count = 0;

