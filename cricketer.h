#pragma once
#include <iostream>
#include "sportsperson.h"

using namespace std;

class Cricketer : public Sportsperson				//inheriting from base class
{
protected:
	string team;
	int runs;

public:
	Cricketer();
	Cricketer(std::string a, int b, std::string c, char d, int e, std::string f, int g);
	int returnRuns();
	float computeAvg();
	void readData(string line, string array[]);
	void printData();

};
