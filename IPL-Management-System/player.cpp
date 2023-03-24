#include "player.hpp"

void p_textColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void p_drawline(char chr)
{
	cout << "\t\t";
	for (int i = 0; i < 104; i++)
	{
		cout <<chr;
	}
	cout << "\n";

}

void player::setDataFromFile(int index, int rowCnt, int columnCnt, string* arr)
{

	for (int j = 0; j < columnCnt; j++)
	{
		if (j == 0)
		{
			id = arr[index + rowCnt * j];
		}
		else if (j == 1)
		{
			name = arr[index + rowCnt * j];
		}
		else if (j == 2)
		{
			role = arr[index + rowCnt * j];
		}
		else if (j == 3)
		{
			runs = stoi(arr[index + rowCnt * j]);
		}
		else if (j == 4)
		{
			wtks = stoi(arr[index + rowCnt * j]);

		}
		else if (j == 5)
		{
			strikeRate = stoi(arr[index + rowCnt * j]);

		}
		else if (j == 6)
		{
			avg = stof(arr[index + rowCnt * j]);
		}
	}



}
void player::updateDataToFile(int index, int rowCnt, int columnCnt, string* arr)
{

	for (int j = 0; j < columnCnt; j++)
	{
		if (j == 0)
		{
			arr[index + rowCnt * j] = id;
		}
		else if (j == 1)
		{
			arr[index + rowCnt * j] = name;
		}
		else if (j == 2)
		{
			arr[index + rowCnt * j] = role;
		}
		else if (j == 3)
		{

			arr[index + rowCnt * j] = to_string(runs);

		}
		else if (j == 4)
		{
			arr[index + rowCnt * j] = to_string(wtks);

		}
		else if (j == 5)
		{
			arr[index + rowCnt * j] = to_string(strikeRate);

		}
		else if (j == 6)
		{
			arr[index + rowCnt * j] = to_string(avg);
		}
	}

}
void player::displayPlayerStats(bool header)
{
	if (header)
	{
		p_textColor(4);
		p_drawline(205);
		cout << "\t\t";
		cout << left << setw(10) << "ID" << left << setw(30) << "NAME" << setw(16) << "ROLE"
			<< setw(12) << "RUNS" << setw(12) << "WICKETS" << setw(16) << "STRIKE RATE"
			<< setw(12) << "AVERAGE" << "\n";
		p_drawline(205);
	}

	cout << "\t\t";
	p_textColor(10);
	cout << left << setw(10) << id << left << setw(30) << name << setw(16) << role
		<< setw(12) << runs << setw(12) << wtks << setw(16) << strikeRate
		<< setw(12) << avg << "\n";
	p_drawline(196);

}
void player::displayAllPlayersStats(player* p, int n)
{
	int i = 0, j = 0, k = 0, pg = 1;
	if (n >= 11)
	{
		k = 11;
	}
	else
		k = n;
	char choice = '@';
	while (choice != '3')
	{
		system("cls");
		cout << "\t\t\t\t\t\t\t+-------------------------+\n";
		cout << "\t\t\t\t\t\t\t|  ALL PLAYER STATISTICS  |\n";
		cout << "\t\t\t\t\t\t\t+-------------------------+\n\n";
		cout << "\t\t" << "PAGE : " << pg<<"\n";
		p_textColor(4);
		p_drawline(205);
		cout << "\t\t";
		cout << left << setw(10) << "ID" << left << setw(30) << "NAME" << setw(16) << "ROLE"
			<< setw(12) << "RUNS" << setw(12) << "WICKETS" << setw(16) << "STRIKE RATE"
			<< setw(12) << "AVERAGE" << "\n";
		p_drawline(205);
		p_textColor(10);
		for (i = j; i < k; i++)
		{
			cout << "\t\t";
			if (p[i].role == "Bowler")
			{
				p_textColor(7);
			}
			else
			{
				p_textColor(11);
			}
		

			cout << left << setw(10) << p[i].id << left << setw(30) << p[i].name << setw(16) << p[i].role
				<< setw(12) << p[i].runs << setw(12) << p[i].wtks << setw(16) << p[i].strikeRate
				<< setw(12) << p[i].avg << "\n";
			p_drawline(196);
			Sleep(10);
		}
		p_textColor(14);
          cout << "\n\t\t" << "1. Previous Page\t\t\t\t2. Next Page\t\t\t\t\t3. Exit\n";
		choice = _getch();
		p_textColor(10);
		
		  if (choice == '1' && j > 0)
		  {
			  pg--;
			  j -= 11;
			  k -= 11;
		  }
		  else if (choice == '2' && i < 88)
		  {
			  pg++;
			  j += 11;
			  k += 11;
		  }
	}
	
	
}