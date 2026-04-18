#pragma once


//DineInOrder.h
//Author: Mahmoud Taha Date[13/4/2026]

#include"Order.h"
#include"../Table.h"

class DineInOrder :public Order
{
private:
	int m_numberOfSeats;
	float m_orderDuration;
	bool m_canShare;
	Table* m_pTable;

public:
	DineInOrder(int,int,int,int,int,int,bool,OrderTypeSec);

	void setNumberOfSeats(int);
	void setOrderDuration(float);
	void setCanShare(bool);
	void setTable(Table*);
	int getNumberOfSeats()const;
	float getOrderDuration()const;
	bool getCanShare()const;
	Table* getTable()const;


	void print(ostream&) override;



};