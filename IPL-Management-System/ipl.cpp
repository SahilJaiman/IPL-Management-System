#include "ipl.hpp"

void i_textColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void  ipl::displayPointsTable(team* t_ptr)
{
	team::displayPointsTable(t_ptr);
}

void ipl::displaySchedule()
{
	i_textColor(6);
	string fileLocation = "data/txt/Match-Schedule.txt";
	system("cls");
	fstream file;
	file.open(fileLocation, ios::in);
	char chr;
	do
	{
		chr = file.get();
		cout << chr;
	} while ((chr != EOF));
	file.close();
	i_textColor(10);
}

void  ipl::getOrangeCap()
{
	int runs[88];
	int index[88];
	for (int i = 0; i < 88; i++)
	{
		runs[i] = p_ptr[i].runs;
	}
	for (int i = 0; i < 88; i++)
	{
		index[i] = i;
	}

	int i, j, min_idx;

	for (i = 0; i < 88 - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < 88; j++)
		{
			if (runs[j] < runs[min_idx])
			{
				min_idx = j;
			}
		}
		swap(&runs[min_idx], &runs[i]);
		swap(&index[min_idx], &index[i]);
	}
	

	for (int i = 0; i < 5; i++)
	{
		int j = index[88 - 1 - i];
		if (i == 0)
		{
			p_ptr[j].displayPlayerStats(true);
		}
		else
		{
			p_ptr[j].displayPlayerStats(false);
		}
		

	}
	cout << "\n";

}

void  ipl::getPurpleCap()
{
	int wtks[88];
	int index[88];
	for (int i = 0; i < 88; i++)
	{
		wtks[i] = p_ptr[i].wtks;
	}
	for (int i = 0; i < 88; i++)
	{
		index[i] = i;
	}

	int i, j, min_idx;

	for (i = 0; i < 88 - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < 88; j++)
		{
			if (wtks[j] < wtks[min_idx])
			{
				min_idx = j;
			}
		}
		swap(&wtks[min_idx], &wtks[i]);
		swap(&index[min_idx], &index[i]);
	}


	for (int i = 0; i < 5; i++)
	{
		int j = index[88 - 1 - i];
		if (i == 0)
		{
			p_ptr[j].displayPlayerStats(true);
		}
		else
		{
			p_ptr[j].displayPlayerStats(false);
		}

	}

	cout << "\n";


}

void ipl::updatePointsTable(team* t_ptr, int team_1, int team_2)
{
	
	
		t_ptr[team_1].noOfMatches += 1;
		t_ptr[team_1].wins += 1;
		t_ptr[team_1].points += 2;

		t_ptr[team_2].noOfMatches += 1;
		t_ptr[team_2].loss += 1;
		t_ptr[team_2].points += 0;

}