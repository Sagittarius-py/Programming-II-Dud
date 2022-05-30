#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;

class DrawGoodCard : public NonBuyableField
{
    DrawGoodCard(DrawGoodCard &source)
    {
        fieldID;
    }

    void Draw(Player &player);
};

class DrawCard : public NonBuyableField
{
    DrawCard(DrawCard &source)
    {
        fieldID;
    }

    void Draw(Player &player);
};

class SpecialCard
{
    int cardID;
    string name;
    string description;

    void cardFunction();
};