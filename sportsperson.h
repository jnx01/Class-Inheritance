#pragma once
#include <iostream>

using namespace std;

class Sportsperson								//Base-class to all other classes in the program
{
protected:
	string playerType;							//Added to help user know what type of sport each player is in
	int recordNum;								//Adds organization and clarity to the program output
	std::string name;							//Using "std::" because something with the name "name" is already defined in namespace std
	char gender;								//I've made the program gender-netural so that data of both male and female athletes can be added
	int matchesPlayed;

public:
	Sportsperson();
	Sportsperson(std::string a, int b, std::string c, char d, int e);
	virtual float computeAvg() = 0;										//Formula differs for footballer and cricketer hence i've made this a pure virtual function
	virtual void readData(string line, string array[]) = 0;				//Each class requires a diferent sized array string for reading data hence i've made this a pure virtual function
	virtual void printData() = 0;										//Each class has different attributes hence each class has a separate print function


	friend ostream& operator << (ostream& out, Sportsperson& s);		//overloading << and >> for displaying data
	friend ostream& operator >> (ostream& out, Sportsperson& s);

};
