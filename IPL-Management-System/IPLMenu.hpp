#pragma once
#include "CsvFileHandling.hpp"	
#include "ipl.hpp"
#include "global.h"
#include "utility.hpp"
using namespace std;
extern ipl ipl2021;


void displayOrangeCap()
{
	system("cls");
	textColor(12);
	cout << "\t\t\t\t\t\t\t+-------------------------+\n";
	cout << "\t\t\t\t\t\t\t|        ORANGE CAP       |\n";
	cout << "\t\t\t\t\t\t\t+-------------------------+\n\n\n";

	ipl2021.getOrangeCap();
}

void displayPurpleCap()
{
	system("cls");
	textColor(13);
	cout << "\t\t\t\t\t\t\t+-------------------------+\n";
	cout << "\t\t\t\t\t\t\t|        PURPLE CAP       |\n";
	cout << "\t\t\t\t\t\t\t+-------------------------+\n\n\n";

	ipl2021.getPurpleCap();
}

void updatePointsTableMenu()
{
	system("cls");
	textColor(10);
	cout << "\t\t\t\t\t\t\t+-------------------------+\n";
	cout << "\t\t\t\t\t\t\t|   UPDATE POINTS TABLE   |\n";
	cout << "\t\t\t\t\t\t\t+-------------------------+\n\n\n";
	textColor(4);
	string team_1, team_2;
	int index_1,index_2;
	bool update = false;
	cout << "\t\t\t\t\t\t\t>>ENTER CODE OF HOME TEAM : ";
	getline(cin, team_1);
	cout << "\n\t\t\t\t\t\t\t>>ENTER CODE OF AWAY TEAM : ";
	getline(cin, team_2);
	index_1 = searchRecord(fileLocation2, *rowCnt2, *columnCnt2, team_1, 1);
	index_2 = searchRecord(fileLocation2, *rowCnt2, *columnCnt2, team_2, 1);
	if (index_1 != -1 && index_2 != -1)
	{
		if (team_1 != team_2)
		{
			char choice = '@';
			textColor(6);
			cout << "\n\t\t\t\t\t\t\t1. " << t[index_1].name << "\n";
			cout << "\n\t\t\t\t\t\t\t2. " << t[index_2].name << "\n";
			textColor(4);
			cout << "\n\t\t\t\t\t\t\tWINNER TEAM [1/2] : ";
			choice = getchar();
			switch (choice)
			{
				case '1':
				{
				ipl2021.updatePointsTable(t, index_1, index_2);
				update = true;
				break;
				}
				case '2':
				{
				ipl2021.updatePointsTable(t, index_2, index_1);
				update = true;
				break;
				}
				default:
				{
				cout << "\n\n\t\t\t\t\t\t\tERROR::INVALID CHOICE\n";
				break;
				}
			}
		}
		else
		{
			cout << "\n\t\t\t\t\t\tERROR::Home and Away Team can't be same\n";
		}
		
	}
	else
	{
		cout << "\n\t\t\t\t\t\t\tERROR::TEAM CODE INVALID\n";
	}

	if (update)
	{
		textColor(6);
		cout << "\n\t\t\t\t\t\t\tPoints Table Updated Succesfully\n";
		char choice = '@';
		cout << "\n\t\t\t\t\t\t\tPress 1. To View Updated Points Table\n";
		choice = _getch();
		if (choice == '1')
		{
			ipl2021.displayPointsTable(t);
		}
	}
	textColor(10);



}
void iplMainMenu()
{
	char choice = '@';
	while (choice != '6')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+-------------------------+\n";
		cout << "\t\t\t\t\t\t\t|         IPL MENU        |\n";
		cout << "\t\t\t\t\t\t\t+-------------------------+\n\n\n";
		textColor(4);
		
		cout << "\t\t\t\t\t\t\t1. VIEW POINTS TABLE\n\n";
		cout << "\t\t\t\t\t\t\t2. VIEW MATCH SCHEDULE\n\n";
		cout << "\t\t\t\t\t\t\t3. VIEW ORANGE CAP\n\n";
		cout << "\t\t\t\t\t\t\t4. VIEW PURPLE CAP\n\n";
		cout << "\t\t\t\t\t\t\t5. UPDATE POINTS TABLE\n\n";
		cout << "\t\t\t\t\t\t\t6. BACK\n";
		
		textColor(10);
		choice = _getch();
		switch (choice)
		{

		case '1':
		{
			
			ipl2021.displayPointsTable(t);
			system("pause");
			break;
		}
		case '2':
		{
			ipl2021.displaySchedule();
			system("pause");
			break;
		}
		case '3':
		{
			displayOrangeCap();
			system("pause");
			break;
		}
		case '4':
		{
			displayPurpleCap();
			system("pause");
			break;
		}
		case '5':
		{
			
			updatePointsTableMenu();
			system("pause");
			break;
		}

		
		}

	}
}

