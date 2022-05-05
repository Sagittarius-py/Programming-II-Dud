#include <iostream>
#include <vector>

#include "1lib.h"

using namespace std;

void display(char data[3][3])
{
    system("cls");
    cout << " " << data[0][0] << " | " << data[0][1] << " | " << data[0][2] << endl
         << "--- --- ---" << endl
         << " " << data[1][0] << " | " << data[1][1] << " | " << data[1][2] << endl
         << "--- --- ---" << endl
         << " " << data[2][0] << " | " << data[2][1] << " | " << data[2][2] << endl;
};

void play(char player, char data[3][3])
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
    cout << "Wpisz wiersz (1-3): ";
    cin >> row;
    cout << "Wpisz kolumne (1-3): ";
    cin >> column;

    if (data[row - 1][column - 1] == ' ')
    {
        data[row - 1][column - 1] = player;
    }
    else
    {
        cout << "Podana komorka jest juz zajeta" << endl;
        play(player, data);
    }
};

int win(char data[3][3], int przekatne)
{
    int wygrana = 0;

    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp = temp + data[i][j];
            if (temp == 'O' * 3 || temp == 'X' * 3)
            {
                wygrana = 1;
                break;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp = temp + data[j][i];
            if (temp == 'O' * 3 || temp == 'X' * 3)
            {
                wygrana = 1;
                break;
            }
        }
    }

    if (przekatne)
    {
        int temp = 0, temp2 = 0;
        for (int i = 0; i < 3; i++)
        {

            for (int j = 0; j < 3; j++)
            {

                if (i == j)
                {
                    temp = temp + data[i][j];
                    if (temp == 'O' * 3 || temp == 'X' * 3)
                    {
                        wygrana = 1;
                        break;
                    }
                }

                if (i == 2 - j)
                {
                    temp2 = temp2 + data[i][j];
                    if (temp2 == 'O' * 3 || temp2 == 'X' * 3)
                    {
                        wygrana = 1;
                        break;
                    }
                }
            }
        }
    }

    return wygrana;
}