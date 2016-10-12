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
		Athlete* temp = new Athlete(tokens.at(0), tokens.at(1), tokens.at(2), tokens.at(3), tokens.at(4), tokens.at(5), tokens.at(6), tokens.at(7));
		tokens.clear();
		table.hash_insert(temp);
		getline(std::cin, in);
	} while (in != "InsertionEnd");

	//table.printHistogram();
	cin >> numberOfCommands;
	cin.ignore();

	for (int index = 0; index < numberOfCommands; index++)
	{
		string command;
		string key;
		vector<string> parameters;
		string buf;
		getline(std::cin, command);
		if (command.substr(0,12) == "hash_display")
		{
			table.hash_display();
		}
		else
		{
			key = command.substr(12);
			int i = 0;
			int pos = key.find(",");

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
					cout << "The medal recipient " << parameters.at(3) << " for " << parameters.at(0) << " with event "<< parameters.at(2) << " deleted" << endl;
				}
				else
				{
					cout << parameters.at(3) << " for " << parameters.at(0) << " with event " << parameters.at(2) << " not found" << endl;
				}
			}
			else if (command.substr(0, 11) == "hash_search")
			{
				Athlete* temp = table.hash_search(key);
				if (temp!=nullptr)
				{
					cout << "The medal recipient " << temp->athlete << " has the medal of " << temp->medal << endl;
				}
				else
				{
					cout << parameters.at(3) << " for " << parameters.at(0) << " with event " << parameters.at(2) << " not found" << endl;
				}
			}
		}
  	}
	table.~HashTable();
	_CrtDumpMemoryLeaks();
}
