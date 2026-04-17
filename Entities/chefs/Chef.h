#pragma once


//Chef.h
//Author:Mahmoud Taha Date[13/4/2026]

#include "../../DEFS.h"

class Chef
{
private:
	const int m_chefSpeed;
	const int m_chefID;
	static int s_count;


public:
	Chef(int);
	~Chef();
	int getChefSpeed()const;
	int getChefID()const;

	void print()const;

};