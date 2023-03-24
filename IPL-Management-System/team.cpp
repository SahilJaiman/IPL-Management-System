#include "team.hpp"

void _swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void t_textColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}
void t_drawline(char chr)
{
	cout << "\t\t";
	for (int i = 0; i < 104; i++)
	{
		cout << chr;
	}
	cout << "\n";

}
void team::displayTeamInfo(int index)
{
	switch (index)
	{
	case 0:
	{
		t_textColor(6);
		break;
	}
	case 1:
	{
		t_textColor(3);
		break;
	}
	case 2:
	{
		t_textColor(5);
		break;
	}
	case 3:
	{
		t_textColor(1);
		break;
	}
	case 4:
	{
		t_textColor(4);
		break;
	}
	case 5:
	{
		t_textColor(13);
		break;
	}
	case 6:
	{
		t_textColor(4);
		break;
	}
	case 7:
	{
		t_textColor(12);
		break;
	}

	}
	string fileLocation = "data/txt/"+code + ".txt";
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
	t_textColor(10);
}

void team::displayTeamPoints(bool header)
{
	if (header)
	{
		t_textColor(4);
		t_drawline(205);
		cout << "\t\t\t";
		cout << left << setw(30) << "TEAM" << left << setw(12) << "PLAYED" << setw(12) << "WON"
			<< setw(12) << "LOST" << setw(12) << "POINTS" << "\n";
		t_drawline(205);
	}
	
	t_textColor(10);
	cout << "\t\t\t";
	cout << left << setw(30) << name << left << setw(12) << noOfMatches << setw(12) << wins
		<< setw(12) << loss << setw(12) << points<<"\n";
	t_drawline(196);

}
void team::setDataFromFile(int index, int rowCnt, int columnCnt, string* arr)
{

	for (int j = 0; j < columnCnt; j++)
	{
		if (j == 0)
		{
			code = arr[index + rowCnt * j];
		}
		else if (j == 1)
		{
			name = arr[index + rowCnt * j];
		}
		else if (j == 2)
		{
			 noOfMatches= stoi(arr[index + rowCnt * j]);
		}
		else if (j == 3)
		{
			wins = stoi(arr[index + rowCnt * j]);
		}
		else if (j == 4)
		{
			loss = stoi(arr[index + rowCnt * j]);

		}
		else if (j == 5)
		{
			points = stoi(arr[index + rowCnt * j]);

		}
	}



}

void team::updateDataToFile(int index, int rowCnt, int columnCnt, string* arr)
{

	for (int j = 0; j < columnCnt; j++)
	{
		if (j == 0)
		{
			arr[index + rowCnt * j] = code;
		}
		else if (j == 1)
		{
			arr[index + rowCnt * j] = name;
		}
		else if (j == 2)
		{
			arr[index + rowCnt * j] = to_string(noOfMatches);
		}
		else if (j == 3)
		{
			arr[index + rowCnt * j] = to_string(wins);
		}
		else if (j == 4)
		{
			arr[index + rowCnt * j] = to_string(loss);

		}
		else if (j == 5)
		{
			arr[index + rowCnt * j] = to_string(points);

		}
	}

}

void team::displayPointsTable(team *t)
{
	int index[] = { 0,1,2,3,4,5,6,7};
	int arr[8];
	int i, j, min_idx;
	for ( i = 0; i< 8; i++)
	{
		arr[i] = t[i].points;
	}

	for (i = 0; i < 8 - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < 8; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		_swap(&arr[min_idx], &arr[i]);
		_swap(&index[min_idx], &index[i]);
	}
	system("cls");
	t_textColor(10);
	cout << "\t\t\t\t\t\t\t+-------------------------+\n";
	cout << "\t\t\t\t\t\t\t|       POINTS TABLE      |\n";
	cout << "\t\t\t\t\t\t\t+-------------------------+\n\n\n";
	t_textColor(4);
	t_drawline(205);
	cout << "\t\t\t";
	cout << left << setw(12) << "POS" << left << setw(36) << "TEAM" << setw(12) << "PLAYED"
		<<setw(12) << "WON" << setw(12) << "LOST" << setw(12) << "POINTS" << "\n";
	t_drawline(205);
	t_textColor(10);

	for ( i = 0; i < 8; i++)
	{
		j = index[8-i-1];
		cout << "\t\t\t";
		
		cout << left << setw(12) << i + 1 << left << setw(36) << t[j].name << setw(12)
			<< t[j].noOfMatches << setw(12) << t[j].wins << setw(12) << t[j].loss
			<< setw(12) << t[j].points<<"\n";
		t_drawline(196);
	}

}