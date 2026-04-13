#pragma once

#include "priQueue.h"

template <typename T>
class DerivedPriQueue : public priQueue<T>
{
public:
	bool deleteElement(T element)
	{
		if (!head) { return false; }


		if (head->getItem == element)
		{
			head = head->getNext();
			return true;
		}

		Node<T>* curr = head->getNext();
		Node<T>* prev = head;
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