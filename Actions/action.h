#pragma once

//Action.h
//Author:Mohamed Medhat Date[13/4/2026]


using namespace std;

#include<iostream>
#include<string>


class Action
{
public:
	Action();
	~Action();

	virtual void act() = 0;
};

