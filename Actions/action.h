#pragma once

//action.h
//Author:Mohamed Medhat Date[13/4/2026]

//#include"../System/Restaurant.h"
#include"../DEFS.h"
#include<fstream>
#include<iostream>
#include<string>

using namespace std;


class Action
{
public:
	Action()=default;
	~Action()=default;

	virtual void act() = 0;
};

