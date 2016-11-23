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
    virtual void makeMove() = 0;
private:
    virtual Card* SearchStrategyCard() = 0;
    virtual Player* SearchStrategyPlayer() = 0;
};

class PlayerType1 : public Player {
public:
    virtual void makeMove() override;

private:
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

class PlayerType2 : public Player {
public:
    virtual void makeMove() override;
private:
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

class PlayerType3 : public Player {
public:
    virtual void makeMove() override;
private:
    int playerIndex;
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

class PlayerType4 : public Player {
public:
    virtual void makeMove() override;
private:
    int playerIndex;
    virtual Card* SearchStrategyCard() override ;
    virtual Player* SearchStrategyPlayer() override ;
};

#endif