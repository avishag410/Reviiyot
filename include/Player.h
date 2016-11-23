#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <Hand.h>

using namespace std;

class Player : public Hand {
private:
    const string name;
public:
    string getName();   //Returns the name of the player
    string toString();
    virtual bool makeMove() = 0;
    virtual void drawCard() = 0;
    virtual Card* giveCards() = 0;

private:
    virtual Card* SearchStrategyCard() = 0;
    virtual Player* SearchStrategyPlayer() = 0;
};

class PlayerType1 : public Player {
public:
    virtual bool makeMove() override;
    virtual void drawCard() override;
    virtual Card* giveCards() override;

private:
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

class PlayerType2 : public Player {
public:
    virtual bool makeMove() override;
    virtual void drawCard() override;
    virtual Card* giveCards() override;
private:
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

class PlayerType3 : public Player {
public:
    virtual bool makeMove() override;
    virtual void drawCard() override;
    virtual Card* giveCards() override;
private:
    int playerIndex;
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

class PlayerType4 : public Player {
public:
    virtual bool makeMove() override;
    virtual void drawCard() override;
    virtual Card* giveCards() override;
private:
    int playerIndex;
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

#endif