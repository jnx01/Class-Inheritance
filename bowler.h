#pragma once
#include <iostream>
#include "cricketer.h"

using namespace std;


class Bowler : virtual public Cricketer						//virtual inheritance so that any class that inherits from both Batter and Bowler does not end up with two copies of Cricketer's data members
{															//Bowler, Batter and Allrounder classes are examples of multi-level inheritance whereas Allrounder is an example of multiple inheritance as well
protected:
	std::string bowlerType;
	int wickets;

public:
	Bowler();
	Bowler(std::string a, int b, std::string c, char d, int e, std::string f, int g, string h, int i);
	void readData(string line, string array[]);
	void readData(int x, string line, string array[]);
	void printData();
	void printData(int x);
};
