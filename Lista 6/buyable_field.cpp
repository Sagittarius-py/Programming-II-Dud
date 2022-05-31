#include <iostream>
#include <string>
#include <vector>

#include "lib.hpp"

using namespace std;

class BuyableField : public Field
{

public:
    int owner;
    int fieldCost;
    int payment;

    BuyableField();

    void payment(BuyableField &source, Player &player, Player &activePlayer)
    {
        // if (player.playerMoney > source.payment)
        // {
        //     player.playerMoney -= source.payment;
        // }
        // else
        // {
        //     // ask player does he want to sell something or bancrupt
        // }
    }
};

//! ROAD FIELD CARD

class RoadField : public BuyableField

{
    int houses;
    int hotel;
    int houseCost;
    int hotelCost;

public:
    RoadField(RoadField &source)
    {
        fieldID;
        source.fieldCost = source.fieldID * 20;
        source.houseCost = source.fieldID * 10;
        source.hotelCost = source.fieldID * 50;
        source.payment = (source.fieldID * 5);

        source.owner = 0;
        source.houses = 0;
    }

    void placeHouse(BuyableField &source, Player &player, Banker &bank)
    {
        // if (source.houses >= 0 && source.houses < 5)
        // {
        //     int temp = 0;
        //     do
        //     {
        //         cout << "At this point on this property there are " << source.houses << " houses." << endl
        //              << "How many houses would u like to place?(max 4 on one field): ";
        //         cin >> temp;
        //     } while (temp < 1 && temp > 4);

        //     if (player.playerMoney > temp * source.houseCost)
        //     {
        //         player.playerMoney -= temp * source.houseCost;
        //         source.houses += temp;
        //         cout << "Congrats, you just bought " << temp << " houses on this field.";
        //     }
        //     else
        //     {
        //         cout << "Sorry but You dont have enought money";
        //     }
        // }
        // source.payment = (source.fieldID * 5) + (source.houseCost * source.houses) ;
    }

    void placeHotel(BuyableField &source, Player &player, Banker &bank)
    {
        // if (source.houses == 4)
        // {
        //     if (player.playerMoney > source.hotelCost)
        //     {
        //         player.playerMoney -= source.hotelCost;
        //         source.houses = 0;
        //         source.hotel = 1;
        //         cout << "Congrats, you just bought hotel on this field.";
        //     }
        //     else
        //     {
        //         cout << "Sorry but You dont have enought money";
        //     }
        //
        // }
        //  source.payment = (source.fieldID * 5) + (source.hotel * 100);
    }

    void sellHouse(BuyableField &source, Player &player, Banker &bank);
    void sellHotel(BuyableField &source, Player &player, Banker &bank);
};

class Station : public BuyableField
{
    Station(Station &source)
    {
        fieldID;
        int fieldCost = 200;
        int payment = 50;
        int owner = 0;
    };
};

class UtilityField : public BuyableField
{
public:
    UtilityField(UtilityField &source, Player &owner)
    {
        int fieldCost = 75;
    };

public:
    void utilityFieldCost();
};