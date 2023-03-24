#pragma once
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <string>
#include "PlayerMenu.hpp"
#include "TeamMenu.hpp"
#include"IPLMenu.hpp"
#include "utility.hpp"

void mainMenu()
{
	char choice = '@';
		while(choice != '4')
		{
			system("cls");
			cout << "\t\t\t\t\t\t\t+-------------------------+\n";
			cout << "\t\t\t\t\t\t\t|  IPL MANAGEMENT SYSTEM  |\n";
			cout << "\t\t\t\t\t\t\t+-------------------------+\n\n\n";
			textColor(4);
			drawLine(7, 26, 205);
			cout << "\n";
			cout << "\t\t\t\t\t\t\t\t1. IPL MENU\n\n";
			
			cout << "\t\t\t\t\t\t\t\t2. TEAM MENU\n\n";
			
			cout << "\t\t\t\t\t\t\t\t3. PLAYER MENU\n\n";
			
			cout << "\t\t\t\t\t\t\t\t4. EXIT\n\n";

			drawLine(7, 26, 205);
			textColor(10);
			choice = _getch();
			switch (choice)
			{
				

				case '1':
				{
					iplMainMenu();
					break;
				}
				case '2':
				{
					teamMainMenu();
					break;
				}
				case '3':
				{
					playerMenu();
					break;
				}
			}

		}
}