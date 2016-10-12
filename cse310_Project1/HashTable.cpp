#include "HashTable.h"


HashTable::HashTable(int sizeIn)
{
	table = new LinkedList[sizeIn];
	size = sizeIn;
}

int HashTable::createKey(string key)
{
	int value = 0;
	for (int i = 0; i < key.size(); i++)
	{
		//value += key[i];
		value += (key[i]*i);
	}
	//return (value * key.length()) % size;
	return value % size;
}

void HashTable::hash_insert(Athlete *toInsert)
{
	int index = createKey(toInsert->key);
	table[index].insert(toInsert);
}

Athlete* HashTable::hash_search(string key)
{
	int index = createKey(key);
	return table[index].search(key);
}

bool HashTable::hash_delete(string key)
{
	int index = createKey(key);
	return table[index].remove(key);
}

void HashTable::hash_display()
{
	for (int index = 0; index < size; index++)
	{
		cout << "index: " << index << ", ";
		table[index].printAll();
	}

}

int HashTable::getNumberOfItems()
{
	int itemCount = 0;
	for (int i = 0; i < size; i++)
	{
		itemCount += table[i].getLength();
	}
	return itemCount;
}

void HashTable::printHistogram()
{
	cout << "\n\nHash Table Contains ";
	cout << getNumberOfItems() << " Items total\n";
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
	delete[] table;
}
