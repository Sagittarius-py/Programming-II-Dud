#include <time.h>
#include <iostream>

#include "1lib.h"

using namespace std;

int main()
{
    int move = 0, wygrana = 0, przekatne = 1;
    char player;
    char data[3][3] = {{' ', ' ', ' '},
                       {' ', ' ', ' '},
                       {' ', ' ', ' '}};

    cout << "Czy przekatne graja?(1 - tak, 0 - nie): ";
    cin >> przekatne;
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

        play(player, data);
        display(data);
        wygrana = win(data, przekatne);
        move++;
    } while (wygrana == 0 && move <= 9);
    cout << "Wygrana gracza " << player;
    return 0;
}