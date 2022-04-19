#include <time.h>
#include <iostream>

using namespace std;

void display(char data[3][3])
{
    cout << " " << data[0][0] << " | " << data[0][1] << " | " << data[0][2] << endl
         << "--- --- ---" << endl
         << " " << data[1][0] << " | " << data[1][1] << " | " << data[1][2] << endl
         << "--- --- ---" << endl
         << " " << data[2][0] << " | " << data[2][1] << " | " << data[2][2] << endl;
}

void play(char player, char *data)
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
    cout << "{1, 2, 3}" << endl
         << "{4, 5, 6}" << endl
         << "{7, 8, 9}" << endl;
    cout << "Wpisz wiersz (1-3): ";
    cin >> row;
    cout << "Wpisz kolumne (1-3): ";
    cin >> column;

    *data[row - 1][column - 1] = player;
}

int main()
{
    int move;
    char player;
    char data[3][3] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};
    if (move % 2 == 0)
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }

    play(player, *data);

    display(data);

    return 0;
}