#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;

class Player
{

    int playerMoney;
    int jailbreaks;
    vector<SpecialCard> *ownedCards = {};

public:
    int playerID;
    int playerStandingField;
    int jailtime;

    Player(Player &player)
    {
        playerID = 1;
        playerMoney = 100000;
    }
    int rollTheDice();
    void getOutJail();
    void goTo(int amount);
    void bancrupt(Player &player);
};