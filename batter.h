#pragma once
#include <iostream>
#include "cricketer.h"

using namespace std;

class Batter : virtual public Cricketer					//virtual inheritance so that any class that inherits from both Batter and Bowler does not end up with two copies of Cricketer's data members
{														//Bowler, Batter and Allrounder classes are examples of multi-level inheritance whereas Allrounder is an example of multiple inheritance as well
protected:
	int centuries;

public:	
	Batter();
	Batter(std::string a, int b, std::string c, char d, int e, std::string f, int g, int h);
	void readData(string line, string array[]);
	void printData();

};
