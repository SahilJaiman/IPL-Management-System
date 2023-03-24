#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include"player.hpp"
#include"team.hpp"
using namespace std;
class ipl
{
public:
	int noOfTeams = 8;
	int noOfMatches = 52;
	string winner = "unknown";
	string orangeCap = "unknown";
	string purpleCap = "unknown";
	string manOfSeries = "unknown";
	team* t_ptr = NULL;
	player* p_ptr = NULL;

	void displayPointsTable(team* t_ptr);
	void displaySchedule();
	void updatePointsTable(team* t_ptr, int winnerTeam, int losserTeam);
	void getOrangeCap();
	void getPurpleCap();

};

