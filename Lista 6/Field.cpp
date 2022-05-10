#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class Player
{
public:
    int playerID;
    int playerMoney;

    Player()
    {
        playerID = 1;
        playerMoney = 100000;
    }

    void bancrupt(Player &player)
    {
    }
};

class RoadField
{
public:
    int fieldID;
    int fieldPlace;
    int fieldCost;
    int houseCost;
    int hotelCost;
    int payment;

    int owner;
    int houses;
    int hotel;

    RoadField(RoadField &source)
    {

        source.fieldPlace = source.fieldID;
        source.fieldCost = source.fieldID * 20;
        source.houseCost = source.fieldID * 10;
        source.hotelCost = source.fieldID * 50;
        source.payment = (source.fieldID * 5) + (source.houseCost * source.houses) + (source.hotel * 100);

        source.owner = 0;
        source.houses = 0;
        source.hotel = 0;
    }

    void fieldBuy(RoadField &source, Player &player)
    {
        if (source.owner == 0)
        {
            source.owner = player.playerID;
            player.playerMoney -= source.fieldCost;
        }
        else if (source.owner != 0)
        {
            cout << "This property had been sold";
        }
    }

    void fieldSell(RoadField &source, Player &buyer)
    {
        if (source.owner == 0)
        {
            cout << "Nobody owns this property yet";
        }
        else if (source.owner != 0)
        {
            // Ask owner if he wants to sell this field
            if (1)
            {
                // run function to :
                // ask owner how much he wants for field
                // ask does buyer agree with price
                // exchange money between players
                owner = buyer.playerID;
            }
            else
            {
                // print that owner doesn't want to sell
            }
        }
    }

    void payment(RoadField &source, Player &player)
    {
        if (player.playerMoney > source.payment)
        {
            player.playerMoney -= source.payment;
        }
        else
        {
            // ask player does he want to sell something or bancrupt
        }
    }

    void placeHouse(RoadField &source, Player &player)
    {
        if (source.houses >= 0 && source.houses < 5)
        {
            int temp = 0;
            do
            {
                cout << "At this point on this property there are " << source.houses << " houses." << endl
                     << "How many houses would u like to place?(max 4 on one field): ";
                cin >> temp;
            } while (temp < 1 && temp > 4);

            if (player.playerMoney > temp * source.houseCost)
            {
                player.playerMoney -= temp * source.houseCost;
                source.houses += temp;
                cout << "Congrats, you just bought " << temp << " houses on this field.";
            }
            else
            {
                cout << "Sorry but You dont have enought money";
            }
        }
    }

    void placeHotel(RoadField &source)
    {
        if (source.houses == 4)
        {

        }
    }
};