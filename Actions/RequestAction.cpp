#pragma once
#include"../HelperFunctions.h"

//RequestAction.cpp 
//Author : Mohamed Medhat Date[17/4/2026]


#include "RequestAction.h"

RequestAction::RequestAction(ifstream&file)
{
	string type;
	file >> type;

	string t;
	file >> t;
	m_requestTimeStep = stoi(t);
	file >> t;
	m_ID = stoi(t);
	file >> t;
	m_sizeWhichIsNumberOfDishesOfOrder = stoi(t);
	file >> t;
	m_orderPrice = stoi(t);
	if (type == "ODN") { m_orderType = ODN; }
	if (type == "ODG") { m_orderType = ODG; }
	if (type == "OVN") { m_orderType = OVN; }
	if (type == "OVG") { m_orderType = OVG; }
	if (type == "OVC") { m_orderType = OVC; }
	if (type == "OT") { m_orderType = OT; }
	if (m_orderType == ODN || m_orderType == ODG)
	{
		file >> t;
		m_numberOfSeatsForDineInOrders = stoi(t);
		file >> t;
		m_orderDurationForDineInOrders = stoi(t);
		file >> t;
		m_canShareForDineInOrders = (t == "Y") ? true : false;
	}
	else if (m_orderType == OVG || m_orderType == OVN || m_orderType == OVC)
	{
		file >> t;
		m_distanceForDeliveryOrders = stoi(t);
	}

}


int RequestAction::getRequestTimeStep()
{
	return m_requestTimeStep;
}

void RequestAction::act()
{

}

void RequestAction::print(ostream&)
{
	cout << "("<<orderTypeToString(m_orderType)<< "," << m_requestTimeStep << "," << m_ID << ")";
}





