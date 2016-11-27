#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

class Player;
#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

class GameManager {
private:
    vector<Player*> players;
    Deck* deck;
    void copy(const GameManager& other);
public:
    GameManager();
    GameManager(Deck& deck);
    GameManager(const GameManager& other);
    void setPlayers(vector<Player*> _players);
    Player* getPlayerWithMaxCards();
    Player* getPlayerWithMaxCards(Player &player);
    Player* getPlayerWithMinCards();
    Player* getPlayerWithMinCards(Player &player);
    Player* getPlayerByPosition(int position);
    Card* getCardFromDeck();
    int getTotalOfPlayers();
    bool thereIsAWinner();
    vector<Player*> getWinners();
    GameManager& operator=(const GameManager& other);
    ~GameManager();
};

#endif