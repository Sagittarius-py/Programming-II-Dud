#include <time.h>
#include <iostream>
#include <vector>

#include "2lib.h"

using namespace std;

int main()
{
    int move = 0, wygrana = 0, wielkosc = 3, przekatne = 1;
    char player;
    std::vector<vector<char>> data;

    cout << "Podaj wielkosc planszy: ";
    cin >> wielkosc;

    cout << "Czy przekatne graja?(1 - tak, 0 - nie): ";
    cin >> przekatne;

    for (int i = 0; i < wielkosc; i++)
    {
        std::vector<char> temp;
        for (int j = 0; j < wielkosc; j++)
        {
            temp.push_back(' ');
        }
        data.push_back(temp);
    }

    system("cls");
    do
    {
        if (move % 2 == 0)
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }

        display(data, wielkosc);
        play(player, data, wielkosc);
        wygrana = win(data, wielkosc, przekatne);
        move++;
    } while (wygrana == 0 && move <= wielkosc * wielkosc);
    display(data, wielkosc);
    cout << "Wygrana gracza " << player;
    return 0;
}