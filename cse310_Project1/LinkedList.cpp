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


// LinkedList :: insert : INSERT function for the linkedlist. One parameter of Athlete type. Inserts at the head of the linked list.
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

// LinkedList :: remove : DELETE Function for linked List. One parameter which is key. Returns true if found and deleted.
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

// LinkedList :: search : SEARCH function for LinkedList. One parameter which is key. Returns the object if found.
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

// printAll : Prints in the required format by calling print on each object in the list.
void LinkedList::printAll()
{
	Athlete *iterator = head;
	cout << "linked list size: " << length << endl << endl;
	if (length == 0)
	{
		cout << "The list is empty" << endl << endl;
	}
	else
	{
		while (iterator != nullptr)
		{
			iterator->print();
			iterator = iterator->next;
		}
	}
}

// 
LinkedList::~LinkedList()
{
	try
	{
		Athlete *current = head;
		Athlete *nextAthlete = nullptr;
		while (current != nullptr)
		{
			nextAthlete = current->next;
			delete(current);
			current = nextAthlete;
		}
		head = nullptr;
	}
	catch (...)
	{
		cout << "Error in deallocation";
	}
}
