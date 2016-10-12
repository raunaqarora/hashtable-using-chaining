#pragma once
#include <iostream>
using namespace std;
class Athlete
{

private:
	string discipline;
	string gender;
	string team_or_ind;
	string event;
	string venue;
	string country;
	
public:
	Athlete *next;
	string key;
	string athlete;
	string medal;
	Athlete(string disciplineIn, string genderIn, string team_or_indIn, string eventIn, string venueIn, string medalIn, string athleteIn, string countryIn);
	void print();
};

