#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sizeOfArray(a)(sizeof(a) / sizeof(*a))
using namespace std;
void drawLine(int tb, int len, char chr)
{
	for (int i = 0; i < tb; i++)
		cout << "\t";
	for (int i = 0; i < len; i++)
		cout << chr;
	cout << "\n";
}

 void textColor(int value)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

 void stringToWords(string str, string* wordStr)
{
	 int i = 0, j = 0, k = 0;
	 size_t l = 0;
	 string temp;
	char ch;
	l = str.length();

	for (i = 0; i < l; i++)
	{
		ch = str[i];
		if (ch != ',')
		{
			temp.push_back(ch);
			j++;
		}
		if ((ch == ',' && j != 0) || i == l - 1)
		{
			wordStr[k] = temp;
			temp.erase();
			j = 0;
			k++;
		}
	}
}
