#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "sportsperson.h"									//including all header files because we want to define the functions of each one
#include "footballer.h"
#include "cricketer.h"
#include "batter.h"
#include "bowler.h"
#include "allrounder.h"

using namespace std;


Sportsperson::Sportsperson() : playerType("none"), recordNum(0), name("Jahanzeb"), gender('M'), matchesPlayed(12)
{}

Sportsperson::Sportsperson(std::string a, int b, std::string c, char d, int e) : playerType(a), recordNum(b), name(c), gender(d), matchesPlayed(e)
{}

ostream& operator << (ostream& out, Sportsperson& s)					//Overloading << to display object of class derived from Sportsperson
{
	out << "\n\nRecord number: " << s.recordNum;
	out << "\nPlayer type: " << s.playerType;
	out << "\nPlayer name: " << s.name;
	out << "\nGender: " << s.gender;
	out << "\nMatches: " << s.matchesPlayed;
	s.printData();														//Calling print function of derived class

	return out;
}

ostream& operator >> (ostream& out, Sportsperson& s)					//Overloading << to display object of class derived from Sportsperson
{
	out << "\n\nRecord number: " << s.recordNum;
	out << "\nPlayer type: " << s.playerType;
	out << "\nPlayer name: " << s.name;
	out << "\nGender: " << s.gender;
	out << "\nMatches: " << s.matchesPlayed;
	s.printData();														//Calling print function of derived class

	return out;
}





Footballer::Footballer() : Sportsperson()			//Calling constructor of base class and also setting values of its own members (can be seen in all other constructors as well)
{
	team = "none";
	position = "none";
	goals = 0;
}

Footballer::Footballer(std::string a, int b, std::string c, char d, int e, std::string f, std::string g, int h) : Sportsperson(a, b, c, d, e)
{
	team = f;
	position = g;
	goals = h;
}

float Footballer::computeAvg()										//defining pure virtual function for Footballer class
{
	float avg;
	avg = float(goals) / float(matchesPlayed);
	return avg;
}

void Footballer::readData(string line, string array[])				//defining pure virtual function for Footballer class
{
	playerType = line;
	recordNum = stoi(array[0]);
	name = array[1];
	string temp = array[2];
	gender = temp[0];
	matchesPlayed = stoi(array[3]);
	team = array[4];
	position = array[5];
	goals = stoi(array[6]);
}

void Footballer::printData()										//defining pure virtual function for Footballer class
{
	cout << "\nCurrent team: " << team;
	cout << "\nPlays at: " << position;
	cout << "\nTotal goals: " << goals;
}






Cricketer::Cricketer() : Sportsperson()
{
	team = "Pakistan";
	runs = 0;
}

Cricketer::Cricketer(std::string a, int b, std::string c, char d, int e, std::string f, int g) : Sportsperson(a, b, c, d, e)
{
	team = f;
	runs = g;
}

int Cricketer::returnRuns()
{
	return runs;
}

float Cricketer::computeAvg()											//defining pure virtual function for Criketer class. computeAvg formula remains same for all derived classes of Cricketer
{
	float avg;
	avg = float(returnRuns()) / float(matchesPlayed);
	return avg;
}

void Cricketer::readData(string line, string array[])					//defining pure virtual function for Criketer class
{
	playerType = line;
	recordNum = stoi(array[0]);
	name = array[1];
	string temp = array[2];
	gender = temp[0];
	matchesPlayed = stoi(array[3]);
	team = array[4];
	runs = stoi(array[5]);
}

void Cricketer::printData()												//defining pure virtual function for Criketer class
{
	cout << "\nCurrent team: " << team;
	cout << "\nTotal runs: " << runs;
}





Batter::Batter() : Cricketer()
{
	centuries = 0;
}

Batter::Batter(std::string a, int b, std::string c, char d, int e, std::string f, int g, int h) : Cricketer(a,b,c,d,e,f,g)
{
	centuries = h;
}

void Batter::readData(string line, string array[])
{
	Cricketer::readData(line, array);							//function overriding in action
	centuries = stoi(array[6]);
}

void Batter::printData()
{
	Cricketer::printData();										//function overriding in action
	cout << "\nCenturies: " << centuries;
}





Bowler::Bowler() : Cricketer()
{
	bowlerType = "Fast bowler";
	wickets = 0;
}

Bowler::Bowler(std::string a, int b, std::string c, char d, int e, std::string f, int g, string h, int i) : Cricketer(a,b,c,d,e,f,g)
{
	bowlerType = f;
	wickets = g;
}

void Bowler::readData(string line, string array[])
{
	Cricketer::readData(line, array);								//function overriding in action
	bowlerType = array[6];
	wickets = stoi(array[7]);
}

void Bowler::readData(int x, string line, string array[])			//Creating another readData function for bowler because when an allrounder object calls it, the array passed as parameter will have data in different locations than the array passed in the previous readData function
{
	bowlerType = array[7];
	wickets = stoi(array[8]);
}

void Bowler::printData()
{
	Cricketer::printData();
	cout << "\nBowler type: " << bowlerType;
	cout << "\nTotal wickets: " << wickets;
}

void Bowler::printData(int x)										//Creating another printData function for bowler because when an allrounder object calls it, I dont want the base class contents (Cricketer) to be printed twice (from Batter's printData and then Bowler's printData)
{
	cout << "\nBowler type: " << bowlerType;
	cout << "\nTotal wickets: " << wickets;
}





Allrounder::Allrounder() : Batter(), Bowler()
{}

Allrounder::Allrounder(std::string a, int b, std::string c, char d, int e, std::string f, int g, int h, std::string i, int j) : Batter(a,b,c,d,e,f,g,h), Bowler(a,b,c,d,e,f,g,i,j)
{}

void Allrounder::readData(string line, string array[])
{
	Batter::readData(line, array);
	Bowler::readData(1, line, array);						//Calling the special version of readData
}

void Allrounder::printData()
{
	Batter::printData();
	Bowler::printData(1);									//Calling the special version of printData
}
