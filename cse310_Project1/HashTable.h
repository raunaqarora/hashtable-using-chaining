#include "LinkedList.h"
#include <iostream>
#include <string>
#include "Athlete.h"

class HashTable
{
private:
	LinkedList * table;
	int size;
	int createKey(string key);

public:
	int numberOfItems;
	HashTable(int sizeIn);
	void hash_insert(Athlete *toInsert);
	Athlete* hash_search(string key);
	bool hash_delete(string key);
	void hash_display();
	void printHistogram();
	~HashTable();
};

