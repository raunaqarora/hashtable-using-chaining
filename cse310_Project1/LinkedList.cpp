#include "LinkedList.h"
#include <iostream>
#include <string>
#include "Athlete.h"

LinkedList::LinkedList()
{
	head = nullptr;
	length = 0;
}

int LinkedList::getLength()
{
	return length;
}

void LinkedList::insert(Athlete *athletetoInsert)
{
	if (length == 0)
	{
		head = athletetoInsert;
		length++;
	}
	else
	{
		athletetoInsert->next = head;
		head = athletetoInsert;
		length++;
	}
}

bool LinkedList::remove(string key)
{
	if (length == 0)
	{
		return false;
	}
	else
	{
		Athlete *iterator = head;
		Athlete *prev = head;
		if (head->key == key)
		{
			head = iterator->next;
			delete iterator;
			length--;
			return true;
		}

		iterator = head->next;
		while (iterator != nullptr)
		{
			if (iterator->key == key)
			{
				prev->next = iterator->next;
				delete iterator;
				length--;
				return true;
			}

			prev = iterator;
			iterator = iterator->next;
		}
		return false;
	}
}

Athlete* LinkedList::search(string key)
{
	if (length == 0)
	{
		return nullptr;
	}
	else
	{
		Athlete *iterator = head;
		while (iterator != nullptr)
		{
			if (iterator->key == key)
			{
				return iterator;
			}
			iterator = iterator->next;
		}
	}
	return nullptr;
}

void LinkedList::printAll()
{
	Athlete *iterator = head;
	cout << "linked list size: " << length << endl;
	while (iterator != nullptr)
	{
		iterator->print();
		iterator = iterator->next;
	}
}

LinkedList::~LinkedList()
{
	Athlete *iterator = head;
	Athlete *prev = head;
	while (iterator != nullptr)
	{
		prev = iterator;
		iterator = iterator->next;
		if (iterator != nullptr)
		{
			delete prev;
		}
	}
	head = nullptr;
}
