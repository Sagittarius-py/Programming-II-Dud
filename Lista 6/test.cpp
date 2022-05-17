#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Player
{
    int money;
    int jailbreaks;
    int jailtime;
    int speeding;
    int fieldIndex;

public:
    Player(char _figure) : figure(_figure) {}
    const char figure;
    void move();
    void getOutOfJail();
    friend bool Bank::setActiveStatus(Player *, BuyableField *, bool);
    friend bool Bank::build(Player *, Street *, int);
    friend bool Bank::transaction(Player *, Player *, int);
    friend class Monopoly;
};

class Field
{
public:
    const string name;
    Field(string _name);
};


class BuyableField : public Field
{
    Player *owner;
    bool active;

public:
    const int price;
    BuyableField(string _name, int _price);
    void newOwner(Player *p);
    void activate();
    void inactivate();
    int rentPrice();
    friend bool Bank::setActiveStatus(Player *, BuyableField *, bool);
};

class Street : public BuyableField
{
    const int rent[5];
    int houses;

public:
    Street(string _name, int _price, int _rent[5]);
    friend bool Bank::build(Player *, Street *, int);
};
class Utility : public BuyableField
{
public:
    Utility(string _name, int _price);
};
class Station : public BuyableField
{
public:
    Station(string _name, int _price);
};
class ChanceField : public Field
{
public:
    ChanceCard getCard();
};
class CommunityChestField : public Field
{
public:
    CommunityChestCard getCard();
};

class Card
{
    Card(string _tekst, void *_fun);

public:
    const string tekst;
    void *fun;
};

class ChanceCard : public Card
{
};
class CommunityChestCard : public Card
{
};

class Monopoly
{
public:
    Monopoly(int numberOfPlayers);
    vector<Player> playerList;
    vector<Field> map;
    vector<ChanceCard> chancesDeck;
    vector<CommunityChestCard> chestsDeck;
    Dice dice;
    Bank bank;
};
class Bank
{
public:
    Bank();
    bool transaction(Player *p1, Player *p2, int amount);
    bool build(Player *p, Street *where, int n); // negative n means demolition
    bool setActiveStatus(Player *P, BuyableField *where, bool newStatus);
};
class Dice
{
    bool speeding;
    int value;

public:
    int roll();
    int getValue();
    bool isSpeeding();
};
class StopWatch
{
    int timestamp;

public:
    void restart();
    int read();
};
class Auction
{
    BuyableField *subject;
    vector<Player *> participating;
    int highBid;

public:
    bool bid(Player *p, int amount);
    Player *winner();
};

int main()
{
    return 0;
}