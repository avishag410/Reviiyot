#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include <iostream>
#include <vector>
#import "Player.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

class GameManager {
private:
    vector<Player*> players;
    Deck* deck;
public:
    GameManager(Deck& deck, vector<Player*> player);
    Player* getPlayerWithMaxCards();
    Player* getPlayerWithMaxCards(Player &player);
    Player* getPlayerWithMinCards();
    Player* getPlayerWithMinCards(Player &player);
    Player* getPlayerByPosition(int position);
    Card* getCardFromDeck();
};

#endif