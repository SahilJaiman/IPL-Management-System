#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
using namespace std;
class team
{
    public:
	string code = "xyz";
	string name = "Unknown";
	int noOfPlayer = 11;
	string captain = "Unknown";
	int noOfMatches = 0;
	int wins = 0;
	int loss = 0;
	int points = 0;
	void displayTeamInfo(int index);
	void displayTeamPoints(bool header);
	static void displayPointsTable(team* t);
	void setDataFromFile(int index, int r, int c, string* arr);
	void updateDataToFile(int index, int r, int c, string* arr);

};

