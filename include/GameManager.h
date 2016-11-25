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
public:
    GameManager(Deck& deck);
    void setPlayers(vector<Player*> _players);
    Player* getPlayerWithMaxCards();
    Player* getPlayerWithMaxCards(Player &player);
    Player* getPlayerWithMinCards();
    Player* getPlayerWithMinCards(Player &player);
    Player* getPlayerByPosition(int position);
    Card* getCardFromDeck();
    int getTotalOfPlayers();
};

#endif