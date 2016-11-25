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
    void copy(const Player& other);
public:
    Player(GameManager &_gameManager, string _name);
    Player(const Player& other);
    string getName();   //Returns the name of the player
    string toString();
    virtual void makeMove() = 0;
    vector<Card*> giveCards(string value);
    Player& operator=(const Player& other);
    virtual ~Player();

protected:
    GameManager* gameManager;
    virtual Card* searchStrategyCard() = 0;
    void drawCard();
};

class PlayerType1 : public Player {
public:
    PlayerType1(GameManager &gameManager, string name);
    PlayerType1(const PlayerType1& other);
    virtual void makeMove() override;
    PlayerType1& operator=(const PlayerType1& other);
    virtual ~PlayerType1();

private:
    virtual Card* searchStrategyCard() override ;
    void copy(const PlayerType1& other);
};

class PlayerType2 : public Player {
public:
    PlayerType2(GameManager &gameManager, string name);
    PlayerType2(const PlayerType2& other);
    virtual void makeMove() override;
    PlayerType2& operator=(const PlayerType2& other);
    virtual ~PlayerType2();
private:
    virtual Card* searchStrategyCard() override ;
    void copy(const PlayerType2& other);
};

class PlayerType3 : public Player {
public:
    PlayerType3(GameManager &gameManager, string name);
    PlayerType3(const PlayerType3& other);
    virtual void makeMove() override;
    PlayerType3& operator=(const PlayerType3& other);
    virtual ~PlayerType3();
private:
    int playerIndex;
    int selfPosition;
    virtual Card* searchStrategyCard() override ;
    void copy(const PlayerType3& other);
};

class PlayerType4 : public Player {
public:
    PlayerType4(GameManager &gameManager, string name);
    PlayerType4(const PlayerType4& other);
    virtual void makeMove() override;
    PlayerType4& operator=(const PlayerType4& other);
    virtual ~PlayerType4();
private:
    int playerIndex;
    int selfPosition;
    virtual Card* searchStrategyCard() override ;
    void copy(const PlayerType4& other);
};

#endif