#include "HashTable.h"

HashTable::HashTable(int sizeIn)
{
	table = new LinkedList[sizeIn];
	size = sizeIn;
}

// Hash Function (h(k)) : Returns an integer for the position of the object to be inserted in the hash table using the string key

int HashTable::createKey(string key)
{
	int value = 0;
	for (int i = 0; i < key.size(); i++)
	{
		value += (key[i]*i);
	}
	return value % size;
}


// hash_insert : Calls create key to get the index of the linked list. Calls insert on the linked list

void HashTable::hash_insert(Athlete *toInsert)
{
	int index = createKey(toInsert->key);
	table[index].insert(toInsert);
	numberOfItems++;
}

// hash_search : Calls create key to get the index of the linked list. Calls search on the linked list

Athlete* HashTable::hash_search(string key)
{
	int index = createKey(key);
	return table[index].search(key);
}

/* hash_delete : Calls create key to get the index of the linked list. Calls remove on the linked list. Returns true if deleted and
				 false if failed.*/

bool HashTable::hash_delete(string key)
{
	int index = createKey(key);
	bool deleted = table[index].remove(key);
	if (deleted == true)
	{
		numberOfItems--;
	}
	return deleted;
}

// hash_display : Iterates through the array and calls printAll on each linked list.
void HashTable::hash_display()
{
	for (int index = 0; index < size; index++)
	{
		cout << "index: " << index << ", ";
		table[index].printAll();
	}

}

/* printHistogram : Prints a histogram showing the distribution of elements across each linked list */
void HashTable::printHistogram()
{
	cout << "\n\nHash Table Contains ";
	cout << numberOfItems << " Items total\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ":\t";
		for (int j = 0; j < table[i].getLength(); j++)
			cout << " X";
		cout << "\n";
	}
}

HashTable::~HashTable()
{
	for (int i = 0; i < size; i++)
	{
		table[i].~LinkedList();
	}
	delete[] table;
}
