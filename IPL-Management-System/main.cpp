#include "global.h"
#include "CsvFileHandling.hpp"
#include "player.hpp"
#include "team.hpp"
#include "ipl.hpp"
#include "MainMenu.hpp"

using namespace std;

//*Global Variables*//

extern player* p;
extern team* t;
extern ipl ipl2021;
extern int* rowCnt1 = new int;
extern int* columnCnt1 = new int;
extern int* rowCnt2 = new int;
extern int* columnCnt2 = new int;

void ConsoleWindow()
{
	//Setting Console Window Properties//
	SetConsoleTitle(_T("IPL-Management-System"));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1280, 720, TRUE);

}

int main()
{
	ConsoleWindow();

	*rowCnt1 = getRecordRowCount(fileLocation1);
	*columnCnt1 = getRecordColumnCount(fileLocation1);
	*rowCnt2 = getRecordRowCount(fileLocation2);
	*columnCnt2 = getRecordColumnCount(fileLocation2);
	// Allocating Memory //
	p = new player[*rowCnt1];
	t = new team[*rowCnt2];
	ipl2021.p_ptr = p;
	ipl2021.t_ptr = t;
	string* playerStats = new string[(*rowCnt1) * long long int(*columnCnt1)];
	string* pointsTable = new string[(*rowCnt2) * long long int(*columnCnt2)];

	//Extracting Data//
	extractFileToArray(fileLocation1, *rowCnt1, *columnCnt1, playerStats);
	extractFileToArray(fileLocation2, *rowCnt2, *columnCnt2, pointsTable);
	for (int i = 0; i < *rowCnt1; i++)
	{
		p[i].setDataFromFile(i, *rowCnt1, *columnCnt1, playerStats);
	}
	for (int i = 0; i < *rowCnt2; i++)
	{
		t[i].setDataFromFile(i, *rowCnt2, *columnCnt2, pointsTable);
	}

	/**/

	mainMenu();

	/**/

	//Updating To File//
	for (int i = 0; i < *rowCnt1; i++)
	{
		p[i].updateDataToFile(i, *rowCnt1, *columnCnt1, playerStats);
	}
	for (int i = 0; i < *rowCnt2; i++)
	{
		t[i].updateDataToFile(i, *rowCnt2, *columnCnt2, pointsTable);
	}
	updateRecord(fileLocation1, *rowCnt1, *columnCnt1, playerStats);
	updateRecord(fileLocation2, *rowCnt2, *columnCnt2, pointsTable);

	//Freeing Memory//
	delete rowCnt1;
	delete rowCnt2;
	delete columnCnt1;
	delete columnCnt2;
	delete[] playerStats;
	delete[] pointsTable;
	delete[] p;
	delete[] t;
	system("pause");
	return 0;
}
