#include <iostream>
#include <vector>

#include "2lib.h"

using namespace std;

void display(vector<vector<char>> data, int size)
{
    system("cls");

    for (int i = 0; i < size; i++)
    {
        for (int l = 0; l < size; l++)
        {
            cout << "-----";
        }
        cout << endl;

        for (int j = 0; j < size; j++)
        {
            cout << "| " << static_cast<char>(data[i][j]) << " |";
        }

        cout << endl;
        if (i == size - 1)
        {
            for (int l = 0; l < size; l++)
            {
                cout << "-----";
            }
        }
    }
    cout << endl;
};

void play(char player, vector<vector<char>> &data, int size)
{
    int column, row;
    if (player == 'O')
    {
        cout << "Ruch wykonuje gracz 'O' " << endl;
    }
    else if (player == 'X')
    {
        cout << "Ruch wykonuje gracz 'X' " << endl;
    }
    cout << "Wpisz wiersz (1 - " << size << "): ";
    cin >> row;
    cout << "Wpisz kolumne (1 - " << size << "): ";
    cin >> column;

    if (data[row - 1][column - 1] == ' ')
    {
        char &temp = data[row - 1][column - 1];
        temp = player;
    }
    else
    {
        cout << "Podana komorka jest juz zajeta" << endl;
        play(player, data, size);
    }
};

int win(vector<vector<char>> data, int wielkosc, int przekatne)
{
    int wygrana = 0;

    for (int i = 0; i < wielkosc; i++)
    {
        int temp = 0;
        for (int j = 0; j < wielkosc; j++)
        {
            temp = temp + data[i][j];
            if (temp == 'O' * wielkosc || temp == 'X' * wielkosc)
            {
                wygrana = 1;
                break;
            }
        }
    }

    for (int i = 0; i < wielkosc; i++)
    {
        int temp = 0;
        for (int j = 0; j < wielkosc; j++)
        {
            temp = temp + data[j][i];
            if (temp == 'O' * wielkosc || temp == 'X' * wielkosc)
            {
                wygrana = 1;
                cout << "wygrana";
                break;
            }
        }
    }

    if (przekatne)
    {
        int temp = 0, temp2 = 0;
        for (int i = 0; i < wielkosc; i++)
        {

            for (int j = 0; j < wielkosc; j++)
            {

                if (i == j)
                {
                    temp = temp + data[i][j];
                    if (temp == 'O' * wielkosc || temp == 'X' * wielkosc)
                    {
                        wygrana = 1;
                        cout << "wygrana";
                        break;
                    }
                }

                if (i == 2 - j)
                {
                    temp2 = temp2 + data[i][j];
                    if (temp2 == 'O' * wielkosc || temp2 == 'X' * wielkosc)
                    {
                        wygrana = 1;
                        cout << "wygrana";
                        break;
                    }
                }
            }
        }
    }

    return wygrana;
};