#pragma once
#include <iostream>
#include "sportsperson.h"

using namespace std;


class Footballer : public Sportsperson						//inheriting from base class
{
private:
	std::string team;
	std::string position;
	int goals;

public:
	Footballer();
	Footballer(std::string a, int b, std::string c, char d, int e, std::string f, std::string g, int h);
	float computeAvg();
	void readData(string line, string array[]);
	void printData();

};
