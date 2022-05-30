#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;

class NonBuyableField
{
public:
    int fieldID;
    NonBuyableField();
};

class Jail : public NonBuyableField
{
    Jail(Jail &source)
    {
        fieldID = 10;
    }
};

class GoToJail : public NonBuyableField
{
    GoToJail(GoToJail &source)
    {
        fieldID = 30;
    }
    void jailed(Player &player);
};

class Parking : public NonBuyableField
{
    Parking(Parking &source)
    {
        fieldID = 20;
    }
    void PayOutBank(Player &player, Banker &bank);
};
