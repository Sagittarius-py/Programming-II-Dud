#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;

class Banker
{
    int allFunds;
    int bankDeposit;

public:
    vector<BuyableField> *unsoldProperties = {};
    void nextPlayer();

    void fieldBuy(BuyableField &source, Player &player, Banker &bank)
    {
        // if (source.owner == 0)
        // {
        //     source.owner = player.playerID;
        //     player.playerMoney -= source.fieldCost;
        // }
        // else if (source.owner != 0)
        // {
        //     cout << "This property had been sold";
        // }
    }

    void fieldSell(BuyableField &source, Player &buyer)
    {
        // if (source.owner == 0)
        // {
        //     cout << "Nobody owns this property yet";
        // }
        // else if (source.owner != 0)
        // {
        //     // Ask owner if he wants to sell this field
        //     if (1)
        //     {
        //         // run function to :
        //         // ask owner how much he wants for field
        //         // ask does buyer agree with price
        //         // exchange money between players
        //         owner = buyer.playerID;
        //     }
        //     else
        //     {
        //         // print that owner doesn't want to sell
        //     }
        // }
    }
};