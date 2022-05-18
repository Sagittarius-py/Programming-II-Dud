#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ! Player & Banker

class Player
{

    int playerMoney;
    int jailbreaks;
    int utilitieCards;

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

class Banker
{
    int allFunds;
    int bankDeposit;

public:
    vector<int> unsoldProperties = {};
    void nextPlayer();
};

class BuyableField
{

public:
    int fieldID;
    int fieldCost;
    int payment;

    int houseCost;
    int hotelCost;

    Player *owner;
    int houses;
    int hotel;

    BuyableField();

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

// ! Non Buyable Fields

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

//! Cards

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

// ! main

int main()
{
    return 0;
}