#pragma once

#include "CsvFileHandling.hpp"	
#include "player.hpp"
#include "global.h"
#include "utility.hpp"
using namespace std;
extern player* p;
extern int* rowCnt1;
extern int* columnCnt1;

void searchMenu()
{
	char choice = '@';
	while (choice != '3')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+------------------------+\n";
		cout << "\t\t\t\t\t\t\t|       SEARCH MENU      |\n";
		cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
		textColor(4);
		cout << "\t\t\t\t\t\t\t1. Search Player By Id\n\n";
		cout << "\t\t\t\t\t\t\t2. Search Player By Name\n\n";
		cout << "\t\t\t\t\t\t\t3. Exit\n\n";
		textColor(10);
		choice = _getch();
		switch (choice)
		{

		case '1':
		{

			string id;
			int index;
			system("cls");
			cout << "\t\t\t\t\t\t\t+------------------------+\n";
			cout << "\t\t\t\t\t\t\t|       SEARCH MENU      |\n";
			cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
			textColor(6);
			cout << "\t\t\t\t\t\t\tEnter Player Id : ";
			cin >> id;
			index = searchRecord(fileLocation1, *rowCnt1, *columnCnt1, id, 1);
			if (index != -1)
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\tRecord Found !!\n";
				textColor(10);
				p[index].displayPlayerStats(true);
				system("pause");
			}
			else
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\t!!Record Not Found !! [Try Again]\n";
				textColor(10);
				system("pause");

			}
			break;
		}

		case '2':
		{

			string name;
			int index;
			system("cls");
			cout << "\t\t\t\t\t\t\t+------------------------+\n";
			cout << "\t\t\t\t\t\t\t|       SEARCH MENU      |\n";
			cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
			textColor(6);
			cout << "\t\t\t\t\t\t\tEnter Player Name : ";
			getline(cin, name);
			index = searchRecord(fileLocation1, *rowCnt1, *columnCnt1, name, 2);
			if (index != -1)
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\tRecord Found !!\n";
				textColor(10);
				p[index].displayPlayerStats(true);
				system("pause");
			}
			else
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\t!! Record Not Found !! [Try Again]\n";
				textColor(10);
				system("pause");
			}

			break;
		}
		}
	}


}
void updateMenu(int i)
{
	int _runs;
	int _wtks;
	int _strikeRate;
	float _avg;
	textColor(4);
	cout << "\t\t\t\t\t\t\tENTER UPDATED INFORMATION\n\n";
	textColor(6);

	cout << "\t\t\t\t\t\t\tENTER RUNS : ";
	cin >> _runs;
	cout << "\n\t\t\t\t\t\t\tENTER WICKETS : ";
	cin >> _wtks;
	cout << "\n\t\t\t\t\t\t\tENTER Strike Rate : ";
	cin >> _strikeRate;
	cout << "\n\t\t\t\t\t\t\tENTER AVERAGE : ";
	cin >> _avg;

	p[i].runs = _runs;
	p[i].wtks = _wtks;
	p[i].strikeRate = _strikeRate;
	p[i].avg = _avg;
	textColor(10);
	cout << "\n";
	cout << "\t\t\t\t\t\t\t+------------------------+\n";
	cout << "\t\t\t\t\t\t\t|   UPDATED INFORMATION  |\n";
	cout << "\t\t\t\t\t\t\t+------------------------+\n\n";
	p[i].displayPlayerStats(true);
	system("pause");

}
void updateMainMenu()
{

	char choice = '@';
	while (choice != '3')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+------------------------+\n";
		cout << "\t\t\t\t\t\t\t|       UPDATE MENU      |\n";
		cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
		textColor(4);
		cout << "\t\t\t\t\t\t\t1. Update Player By Id\n\n";
		cout << "\t\t\t\t\t\t\t2. Update Player By Name\n\n";
		cout << "\t\t\t\t\t\t\t3. Exit\n";
		textColor(10);
		choice = _getch();
		switch (choice)
		{

		case '1':
		{

			string id;
			int index;
			system("cls");
			cout << "\t\t\t\t\t\t\t+------------------------+\n";
			cout << "\t\t\t\t\t\t\t|       UPDATE MENU      |\n";
			cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
			textColor(6);
			cout << "\t\t\t\t\t\t\tEnter Player Id : ";
			cin >> id;
			index = searchRecord(fileLocation1, *rowCnt1, *columnCnt1, id, 1);
			if (index != -1)
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\tRecord Found !!\n\n";
				textColor(10);
				updateMenu(index);
			}
			else
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\t!! Record Not Found !! [Try Again]\n";
				textColor(10);
				system("pause");
			}
			break;
		}

		case '2':
		{

			string name;
			int index;
			system("cls");
			cout << "\t\t\t\t\t\t\t+------------------------+\n";
			cout << "\t\t\t\t\t\t\t|       UPDATE MENU      |\n";
			cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
			textColor(6);
			cout << "\t\t\t\t\t\t\tEnter Player Name : ";
			getline(cin, name);
			index = searchRecord(fileLocation1, *rowCnt1, *columnCnt1, name, 2);
			if (index != -1)
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\tRecord Found !!\n\n";
				textColor(10);
				updateMenu(index);
			}
			else
			{
				textColor(4);
				cout << "\n\t\t\t\t\t\t\t!! Record Not Found !! [Try Again]\n";
				textColor(10);
				system("pause");
			}

			break;
		}
		}
	}


}

void playerMenu()
{

	char choice = '@';
	while (choice != '4')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+------------------------+\n";
		cout << "\t\t\t\t\t\t\t|       PLAYER MENU      |\n";
		cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
		textColor(4);
		cout << "\t\t\t\t\t\t\t1. SEARCH PLAYER\n\n";
		cout << "\t\t\t\t\t\t\t2. UPDATE PLAYER STATISTICS\n\n";
		cout << "\t\t\t\t\t\t\t3. VIEW ALL PlAYER STATISTICS\n\n";
		cout << "\t\t\t\t\t\t\t4. BACK\n";
		textColor(10);
		choice = _getch();
		switch (choice)
		{

		case '1':
		{
			searchMenu();
			break;
		}

		case '2':
		{
			updateMainMenu();
			break;

		}

		case '3':
		{
			system("cls");
			player::displayAllPlayersStats(p, *rowCnt1);
			break;
		}



		}

	}

}


