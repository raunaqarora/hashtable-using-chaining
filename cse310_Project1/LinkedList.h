#include "Athlete.h"

class LinkedList
{
private:
	Athlete *head;
	int length;
public:
	LinkedList();
	~LinkedList();
	void insert(Athlete *athletetoInsert);
	bool remove(string key);
	Athlete* search(string key);
	void printAll();
	int getLength();
};

