#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "utility.hpp"

using namespace std;

void displayFileToConsole(string fileLocation)
{
    fstream file;
    file.open(fileLocation, ios::in);
    char chr;
    do
    {
        chr = file.get();
        cout << chr;
    } while ((chr != EOF));
    file.close();
}
int getRecordRowCount(string fileLocation)
{
    fstream file;
    file.open(fileLocation, ios::in);
    int rowCnt = 0;
    char chr=file.get();
    while (chr != EOF)
    {
        chr = file.get();
        if (chr == '\n')
        {
            rowCnt++;
        }
    }
    file.close();
    return rowCnt + 1;
}
int getRecordColumnCount(string fileLocation)
{
    fstream file;
    file.open(fileLocation, ios::in);
    int columnCnt = 0;
    char chr=file.get();
    while (chr != '\n')
    {
        chr = file.get();
        if (chr == ',')
        {
            columnCnt++;
        }
    }
    file.close();
    return columnCnt + 1;
}

int searchRecord(string fileLocation, int row, int column, string keyValue, int keyIndex)
{
    fstream file;
    file.open(fileLocation, ios::in);
    string* rowData = new string[row];
    string* token = new string[column];
    int index = -1;
    bool recordFound = false;
    keyIndex--;
    for (int i = 0; i < row; i++)
    {
        getline(file, rowData[i]);
        stringToWords(rowData[i], token);
        if (token[keyIndex] == keyValue)
        {
            index = i;
            recordFound = true;
            break;
        }
    }
    file.close();
    delete[] rowData;
    delete[] token;
    return index;
}

void extractFileToArray(string fileLocation, int row, int column, string* arr)
{
    fstream file;
    file.open(fileLocation, ios::in);
    string rowData;
    string* token = new string[column];
 
    for (int i = 0; i < row; i++)
    {
        rowData.clear();
        getline(file, rowData);
        stringToWords(rowData, token);
        //Columns
        for (int j = 0; j < column; j++)
        {
            arr[i + row * j] = token[j];
        }
        
    }
    file.close();
    delete[] token;
}

void updateRecord(string fileLocation, int row, int column, string* arr)
{
    fstream file;
    file.open(fileLocation, ios::out | ios::trunc);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            file << arr[i + row * j];
            if (j == column - 1 && i!=row-1)
            {
                file << "\n";
            }
            else
            {
                file << ",";
            }
        }
    }
    file.close();
}
