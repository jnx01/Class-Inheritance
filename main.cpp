#include <iostream>
#include <stdlib.h>							//to use system function
#include <windows.h>						//to use sleep function
#include <fstream>
#include <string>
#include <assert.h>
#include "footballer.h"						//only including these 2 files. All other files are accessible through these 2 files
#include "allrounder.h"

using namespace std;

int main()
{
	ifstream in;
	string line;
	const int size = 10;

	Sportsperson* arr[size];							//Creating pointer array because you can't create objects of a class with pure virtual function


	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcome to Player Information System!";
	Sleep(3000);
	system("CLS");

	cout << "\n\n\n\n\t\t\tPress enter to see the information of all the players in the database.";
	cin.ignore();
	system("CLS");
	cout << "\nPlayer Info:\n\n";

	in.open("1.txt", ios::in);
	if (in.good())
	{
		for(int i = 0; i < size; ++i)
		{
			getline(in, line);
			if (line == "Footballer")						//Creating suitable objects and calling suitable functions depending on data type
			{
				arr[i] = new Footballer;
				assert(arr[i] != 0);						//Ensuring memory has been assigned

				string* array = new string[7];				//To store lines from file
				assert(array != 0);							//Ensuring memory has been assigned

				for (int i = 0; i < 7; ++i)
				{
					getline(in, array[i]);
				}
				arr[i]->readData(line, array);
				
				delete[] array;								//Freeing memory

			}

			else if (line == "Batter")
			{
				arr[i] = new Batter;
				assert(arr[i] != 0);

				string* array = new string[7];
				assert(array != 0);


				for (int i = 0; i < 7; ++i)
				{
					getline(in, array[i]);

				}
				arr[i]->readData(line, array);

				delete[] array;

			}

			else if (line == "Bowler")
			{
				arr[i] = new Bowler;
				assert(arr[i] != 0);

				string* array = new string[8];
				assert(array != 0);

				for (int i = 0; i < 8; ++i)
				{
					getline(in, array[i]);
				}
				arr[i]->readData(line, array);
				
				delete[] array;

			}

			else
			{
				arr[i] = new Allrounder;
				assert(arr[i] != 0);

				string* array = new string[9];
				assert(array != 0);


				for (int i = 0; i < 9; ++i)
				{
					getline(in, array[i]);
				}
				arr[i]->readData(line, array);
				
				delete[] array;

			}

		}
		in.close();
	}
	else
		cout << "\n\tSorry, the file could not be opened for reading.";

	for (int i = 0; i < size; ++i)
	{

		cout >> *arr[i];															//Using operator overloaded function. Didn't get a chance to use "<<" but I have defined that function as well
		cout << "\nAverage: " << arr[i]->computeAvg() << endl;						//Displaying average along with other data
	}

	cout << "\n\n\tPress enter to exit program.";
	cin.ignore();
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tGoodbye!\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
