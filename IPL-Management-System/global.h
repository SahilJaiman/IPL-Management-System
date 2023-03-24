#pragma once
#include <tchar.h>
#include <cwchar>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include"player.hpp"
#include"team.hpp"
#include"ipl.hpp"
/*Global Variables*/
int *rowCnt1;
int *columnCnt1;
int *rowCnt2;
int *columnCnt2;
string fileLocation1 = "data/csv/playerStats.csv";
string fileLocation2 = "data/csv/pointsTable.csv";

player* p;
team* t;
ipl ipl2021;
