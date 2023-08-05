#pragma once
#include <iostream>
#include "batter.h"
#include "bowler.h"

using namespace std;


class Allrounder : public Batter, public Bowler						//Multiple inheritance
{
public:
	Allrounder();
	Allrounder(std::string a, int b, std::string c, char d, int e, std::string f, int g, int h, std::string i, int j);
	void readData(string line, string array[]);
	void printData();
};
