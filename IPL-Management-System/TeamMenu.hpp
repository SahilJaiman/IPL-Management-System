#pragma once

#include "CsvFileHandling.hpp"	
#include "player.hpp"
#include "team.hpp"
#include "global.h"
#include"utility.hpp"

void viewPoints(int index)
{
	
	cout << "\n";
	cout << "\t\t\t\t\t\t\t\tTEAM POINTS\n";
	drawLine(8, 11, 196);
	t[index].displayTeamPoints(true);
}

void viewinfo(int index)
{
	t[index].displayTeamInfo(index);
}

void teamMenu(int index)
{

	char choice = '@';
	while (choice != '3')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+-----------------------------+\n";
		cout << "\t\t\t\t\t\t\t";
		if (index != 6)
		{
			cout << "\t";
		}
		else
		{
			cout << "  ";
		}
			
		cout << setw(25) << left << t[index].name;
		cout << "\n";
		cout << "\t\t\t\t\t\t\t+-----------------------------+\n\n\n";

		textColor(4);
		cout << "\t\t\t\t\t\t\t1.View Team Information\n\n";
		cout << "\t\t\t\t\t\t\t2.View Team Points\n\n";
		cout << "\t\t\t\t\t\t\t3.Back\n";
		textColor(10);
		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			viewinfo(index);
			system("pause");
			break;
		}
		case '2':
		{
			viewPoints(index);
			system("pause");
			break;
		}

		}

	}

}




void teamMainMenu()
{
	system("cls");
	char choice = '@';
	while (choice != '9')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+------------------------+\n";
		cout << "\t\t\t\t\t\t\t|        TEAM MENU       |\n";
		cout << "\t\t\t\t\t\t\t+------------------------+\n\n\n";
		textColor(4);
		cout << "\t\t\t\t\t\t\tSelect Team\n";
		cout << "\n";
		textColor(225);
		cout << "\t\t\t\t\t\t\t1.Chennai Super Kings\n";
		cout << "\n";
		textColor(52);
		cout << "\t\t\t\t\t\t\t2.Delhi Champions\n";
		cout << "\n";
		textColor(86);
		cout << "\t\t\t\t\t\t\t3.Kolkata Knight Riders\n";
		cout << "\n";
		textColor(22);
		cout << "\t\t\t\t\t\t\t4.Mumbai Indians\n";
		cout << "\n";
		textColor(78);
		cout << "\t\t\t\t\t\t\t5.Punjab Kings\n";
		cout << "\n";
		textColor(219);
		cout << "\t\t\t\t\t\t\t6.Rajasthan Royals\n";
		cout << "\n";
		textColor(100);
		cout << "\t\t\t\t\t\t\t7.Royal Challenger Bangalore\n";
		cout << "\n";
		textColor(192);
		cout << "\t\t\t\t\t\t\t8.Sunrisers Hyderabad\n";
		textColor(10);
		cout << "\n";
		cout << "\t\t\t\t\t\t\t9.Back\n";

		choice = _getch();
		switch (choice)
		{
		case '1':
		{
			teamMenu(0);
			break;
		}

		case '2':
		{
			teamMenu(1);
			break;
		}

		case '3':
		{
			teamMenu(2);
			break;
		}

		case '4':
		{
			teamMenu(3);
			break;
		}

		case '5':
		{
			teamMenu(4);
			break;
		}

		case '6':
		{
			teamMenu(5);
			break;
		}

		case '7':
		{
			teamMenu(6);
			break;
		}

		case '8':
		{
			teamMenu(7);
			break;
		}


		}

	}

}
