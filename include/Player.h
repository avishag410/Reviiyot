#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include <Hand.h>
#include <Deck.h>
#include "GameManager.h"

using namespace std;

class Player : public Hand {
private:
    const string name;
public:
    Player(GameManager::GameManager &_gameManager, string _name);
    string getName();   //Returns the name of the player
    string toString();
    virtual void makeMove() = 0;
    vector<Card*> giveCards(string value);

protected:
    GameManager* gameManager;
    virtual Card* searchStrategyCard() = 0;
    void drawCard();
};

class PlayerType1 : public Player {
public:
    PlayerType1(GameManager::GameManager &gameManager, string name);
    virtual void makeMove() override;

private:
    virtual Card* searchStrategyCard() override ;
};

class PlayerType2 : public Player {
public:
    PlayerType2(GameManager::GameManager &gameManager, string name);
    virtual void makeMove() override;
private:
    virtual Card* searchStrategyCard() override ;
};

class PlayerType3 : public Player {
public:
    PlayerType3(GameManager::GameManager &gameManager, string name);
    virtual void makeMove() override;
private:
    int playerIndex;
    int selfPosition;
    virtual Card* searchStrategyCard() override ;
};

class PlayerType4 : public Player {
public:
    PlayerType4(GameManager::GameManager &gameManager, string name);
    virtual void makeMove() override;
private:
    int playerIndex;
    int selfPosition;
    virtual Card* searchStrategyCard() override ;
};

#endif