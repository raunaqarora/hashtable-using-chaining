#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include <string>
#include "HashTable.h"
#include <vector>
#include <sstream> 
#include "Athlete.h"

using namespace std;

/* Hash Function (h) : h(key) = sum(key[i]*i) % size
	int HashTable::createKey(string key)
	{
		int value = 0;
		for (int i = 0; i < key.size(); i++)
		{
			value += (key[i]*i);
		}
		return value % size;
	}

	Analysis: I wrote a short function that prints a histogram to show the distribution of elements amongst all linkedLists. 
				This made me realize that my initial hash function ( sum(key[i]) % size ) was creating too many collisions.
				I tried a few different functions and found this function to create the most balanced distribution. Since, in the 
				sample input there are 44 entries, ideally a hash function should assign 3-4 entries for each list. Initially I
				had a list with 7 entries and multiple lists with none. After improving the algorithm I could get it down to a more
				even distribution.
*/

int main()
{
	int size;
	int numberOfCommands;
	string in;
	string token;
	cin >> size;
	cin.clear();
	cin.ignore();
	HashTable table = HashTable(size);
	vector<string> tokens;

	try
	{
		getline(std::cin, in);
		do
		{
			int i = 0;
			int pos = in.find(",");

			while (pos != string::npos)
			{
				tokens.push_back(in.substr(i, pos - i));
				i = ++pos;
				pos = in.find(",", pos);

				if (pos == string::npos)
					tokens.push_back(in.substr(i, in.length()));
			}
			Athlete* temp = new Athlete(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), tokens.at(4), tokens.at(5), 
				tokens.at(6), tokens.at(7));
			tokens.clear();
			table.hash_insert(temp);
			getline(std::cin, in);
		} while (in != "InsertionEnd");
	}
	catch (...)
	{
		cout << "Unexpected Input";
	}


	try
	{
		//table.printHistogram();
		cin >> numberOfCommands;
		cin.ignore();
	}
	catch (...)
	{
		cout << "Type mismatch";
	}

	for (int index = 0; index < numberOfCommands; index++)
	{
		string command;
		string key;
		vector<string> parameters;
		string buf;
		getline(std::cin, command);
		if (command.substr(0, 12) == "hash_display")
		{
			table.hash_display();
		}
		else
		{
			key = command.substr(12);
			int i = 0;
			int pos = key.find(",");

			try
			{
				while (pos != string::npos)
				{
					parameters.push_back(key.substr(i, pos - i));
					i = ++pos;
					pos = key.find(",", pos);

					if (pos == string::npos)
						parameters.push_back(key.substr(i, key.length()));
				}
				key = parameters.at(0) + parameters.at(1) + parameters.at(2) + parameters.at(3);

				if (command.substr(0, 11) == "hash_delete")
				{
					bool isfound = table.hash_delete(key);
					if (isfound == true)
					{
						cout << "The medal recipient " << parameters.at(3) << " for " << parameters.at(0) << " with event " << parameters.at(2) << " deleted" << endl;
					}
					else
					{
						cout << parameters.at(3) << " for " << parameters.at(0) << " with event " << parameters.at(2) << " not found" << endl;
					}
				}
				else if (command.substr(0, 11) == "hash_search")
				{
					Athlete* temp = table.hash_search(key);
					if (temp != nullptr)
					{
						cout << "The medal recipient " << temp->athlete << " has the medal of " << temp->medal << endl;
					}
					else
					{
						cout << parameters.at(3) << " for " << parameters.at(0) << " with event " << parameters.at(2) << " not found" << endl;
					}
				}
			}
			catch (...)
			{
				cout << "Invalid arguments";
			}
		}
	}

	table.~HashTable();
	_CrtDumpMemoryLeaks();
}
