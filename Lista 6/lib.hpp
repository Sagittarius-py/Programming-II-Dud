#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Banker
{
    int allFunds;
    int bankDeposit;

public:
    vector<BuyableField> *unsoldProperties = {};
    void nextPlayer();
    void fieldBuy(BuyableField &source, Player &player, Banker &bank);
    void fieldSell(BuyableField &source, Player &buyer);
};

class NonBuyableField
{
public:
    int fieldID;
    NonBuyableField();
};

class Jail : public NonBuyableField
{
    Jail(Jail &source);
};

class GoToJail : public NonBuyableField
{
    GoToJail(GoToJail &source);
    void jailed(Player &player);
};

class Parking : public NonBuyableField
{
    Parking(Parking &source);
    void PayOutBank(Player &player, Banker &bank);
};

class BuyableField
{
    int owner;

public:
    int fieldID;
    int fieldCost;
    int payment;

    BuyableField();

    void payment(BuyableField &source, Player &player, Player &activePlayer);
};

//! ROAD FIELD CARD

class RoadField : public BuyableField

{
    int houses;
    int hotel;
    int houseCost;
    int hotelCost;

    RoadField(RoadField &source);
    void placeHouse(BuyableField &source, Player &player, Banker &bank);
    void placeHotel(BuyableField &source, Player &player, Banker &bank);
    void sellHouse(BuyableField &source, Player &player, Banker &bank);
    void sellHotel(BuyableField &source, Player &player, Banker &bank);
};

class Station : public BuyableField
{
    Station(Station &source);
};

class UtilityField : public BuyableField
{
    UtilityField(UtilityField &source, Player &owner);

public:
    void utilityFieldCost();
};

class Player
{

    int playerMoney;
    int jailbreaks;
    vector<SpecialCard> *ownedCards = {};

public:
    int playerID;
    int playerStandingField;
    int jailtime;

    Player(Player &player);
    int rollTheDice();
    void getOutJail();
    void goTo(int amount);
    void bancrupt(Player &player);
};

class DrawGoodCard : public NonBuyableField
{
    DrawGoodCard(DrawGoodCard &source);
    void Draw(Player &player);
};

class DrawCard : public NonBuyableField
{
    DrawCard(DrawCard &source);
    void Draw(Player &player);
};

class SpecialCard
{
    int cardID;
    string name;
    string description;

    void cardFunction();
};