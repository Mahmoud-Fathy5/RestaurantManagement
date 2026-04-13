#pragma once

#include "LinkedQueue.h"

template<typename T>
class DerivedQueue : public LinkedQueue<T>
{
public:
	bool deleteElement(T element)
	{
		if (!frontPtr) { return false; }


		if (frontPtr->getItem == element)
		{
			frontPtr = frontPtr->getNext();
			return true;
		}
		
		Node<T>* curr = frontPtr->getNext();
		Node<T>* prev = frontPtr;
		while (curr)
		{
			if (curr->getItem() == element)
			{
				prev->setNext(curr->getNext());
				return true;
			}
			prev = curr;
			curr = curr->getNext();
		}
		return false;
	}
};