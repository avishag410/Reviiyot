#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <vector>
#include <Hand.h>
#include <Deck.h>

using namespace std;

class Player : public Hand {
private:
    const string name;
    Deck* deck;
public:
    Player(Deck* deck);
    string getName();   //Returns the name of the player
    string toString();
    virtual void makeMove() = 0;
    vector<Card*> giveCards(string value);

protected:
    virtual Card* searchStrategyCard() = 0;
    virtual Player* searchStrategyPlayer() = 0;
    void drawCard();
};

class PlayerType1 : public Player {
public:
    PlayerType1(Deck* deck);
    virtual void makeMove() override;

private:
    virtual Card* searchStrategyCard() override ;
    virtual Player* searchStrategyPlayer() override ;
};

class PlayerType2 : public Player {
public:
    PlayerType2(Deck* deck);
    virtual void makeMove() override;
private:
    virtual Card* searchStrategyCard() override ;
    virtual Player* searchStrategyPlayer() override ;
};

class PlayerType3 : public Player {
public:
    PlayerType3(Deck* deck);
    virtual void makeMove() override;
private:
    int playerIndex;
    virtual Card* searchStrategyCard() override ;
    virtual Player* searchStrategyPlayer() override ;
};

class PlayerType4 : public Player {
public:
    PlayerType4(Deck* deck);
    virtual void makeMove() override;
private:
    int playerIndex;
    virtual Card* searchStrategyCard() override ;
    virtual Player* searchStrategyPlayer() override ;
};

#endif