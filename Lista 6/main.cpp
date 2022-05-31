#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;

void gameStart(vector<Player> players)
{
    int playerCount;
    cout << "How many players would you to play: ";
    cin >> playerCount;

    for (int i = 0; i < playerCount; i++)
    {
        *players.push_back(Player::Player);
    }
};

void generateBoard(vector<Field> board)
{
    int roadFields[22] = {1, 2, 6, 8, 9, 11, 13, 14, 16, 18, 19, 21, 23, 24, 26, 27, 29, 31, 32, 34, 37, 29};

    for (int i = 0; i < 40; i++)
    {
        if (find(begin(roadFields), end(roadFields), i))

            board.push_back(Field::);
    }
}

void game()
{
    int choice = 0;
    cout << "";
};

int main()
{
    vector<Field> board;
    vector<Player> players;

    return 0;
}