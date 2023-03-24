#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<iomanip>

using namespace std;
class player
{
public:
	string  id =  "unknown";
	string role = "Unknown";
	string name = "Unknown";
	int runs = 0;
	int wtks = 0;
	int strikeRate = 0;
	float avg = 0;
	void setDataFromFile(int index, int r, int c, string* arr);
	void updateDataToFile(int index, int r, int c, string* arr);
	void displayPlayerStats(bool header);
	static void displayAllPlayersStats(player* p, int n);
};

