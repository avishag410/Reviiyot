#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <fstream>
#include "Player.h"
#include "Deck.h"
#include "GameManager.h"

using namespace std;

class Game {
private:
    vector<Player *> players;  //The list of the players
    Deck deck;                 //The deck of the game
    int maxNumber;
    int printMode;
    int turnsCounter;
    string configurationPath;
    GameManager gameManager;
    void file_reader(string path);
    void createPLayer(istream& stream, string line);
    void distributeCards();
    void copy(const Game& other);
public:
    Game(char* configurationFile);
    Game(const Game& other);
    void init();
    void play();
    void printState();        //Print the state of the game as described in the assignment.
    void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.
    Game& operator=(const Game& other);
    virtual ~Game();
};

#endif