#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player
{
    int playerID;
    int playerMoney;
    int playerStandingField;
    int jailtime;
    int jailbreaks;

    Player()
    {
        playerID = 1;
        playerMoney = 100000;
    }

    void rollTheDice();

    void goTo();

    void bancrupt(Player &player);
};

class Banker
{
    int allFunds;
    int bankDeposit;
    vector<int> unsoldProperties = {};
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

    void fieldSell(RoadField &source, Player &buyer)
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

    void payment(RoadField &source, Player &player)
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

    void placeHouse(RoadField &source, Player &player)
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
    }

    void placeHotel(RoadField &source, Player &player)
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
        // }
    }
};

class Station
{
    int fieldID;
    int fieldPlace;
    int fieldCost;
    int payment;
    int owner;

    Station(Station &source)
    {
        int fieldCost = 200;
        int payment = 200;
        int owner = 0;
    };

    void fieldBuy(Station &source, Player &player);
    void fieldSell(Station &source, Player &player);
    void payment(Station &source, Player &player);
};

class Jail
{
    int fieldID;
    int fieldPlace;
};

class GoToJail
{
    int fieldID;
    int fieldPlace;

    void jailed(Player &player);
};

class Parking
{
    int fieldID;
    int fieldPlace;

    void PayOutBank(Player &player, Banker &bank);
};

class UtilityField
{
    int fieldID;
    int fieldPlace;
    int fieldCost;
    int payment;
    int owner;

    UtilityField(UtilityField &source)
    {
        int fieldCost = 75;
        int owner = 0;
    };

    void fieldBuy(UtilityField &source, Player &player);
    void fieldSell(UtilityField &source, Player &player);
    void payment(UtilityField &source, Player &player);
};

main()
{
    return 0;
}