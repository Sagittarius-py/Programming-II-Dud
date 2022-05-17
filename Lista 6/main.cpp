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

    Player(Player &player)
    {
        playerID = 1;
        playerMoney = 100000;
    }

    int rollTheDice();

    void goTo(int amount);

    void bancrupt(Player &player);
};

class Banker
{
    int allFunds;
    int bankDeposit;
    vector<int> unsoldProperties = {};
};

class BuyableField
{

public:
    int fieldID;
    int fieldCost;
    int payment;

    int houseCost;
    int hotelCost;

    int owner;
    int houses;
    int hotel;

    BuyableField(BuyableField &source)
    {

        source.fieldCost = source.fieldID * 20;
        source.payment = (source.fieldID * 5);

        source.owner = 0;
        source.houses = 0;
        source.hotel = 0;
    }

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
    int fieldID;

    int payment;

    RoadField(BuyableField &source)
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
    UtilityField(UtilityField &source)
    {
        int fieldCost = 75;
        int owner = 0;
    };
};

class NonBuyableField
{
public:
    int fieldID;
    NonBuyableField(NonBuyableField &source)
    {
        fieldID;
    }
};

class Jail : public NonBuyableField
{
    Jail(Jail &source)
    {
        fieldID;
    }
};

class GoToJail : public NonBuyableField
{
    void jailed(Player &player);
};

class Parking : public NonBuyableField
{
    void PayOutBank(Player &player, Banker &bank);
};



main()
{
    return 0;
}