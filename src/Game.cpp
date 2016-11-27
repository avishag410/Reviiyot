#include <iostream>
#include <Player.h>
#include <Deck.h>
#include <Game.h>
#include <GameManager.h>
#include <fstream>
#include "../include/Game.h"

using namespace std;

Game::Game(char* configurationFile)
        :players(), deck("", 0), maxNumber(0), printMode(0), turnsCounter(0), configurationPath(configurationFile), gameManager(deck){}

Game::Game(const Game& other):players(), deck("", 0), maxNumber(other.maxNumber), printMode(other.printMode), turnsCounter(other.printMode),
                              configurationPath(other.configurationPath), gameManager() {
    Game::copy(other);
}

void Game::file_reader(string path) {
    string line;
    ifstream myfile(path);

    if (myfile.is_open())
    {
        // Read mode
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            printMode = stoi(line);
        }

        // Read max number
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            maxNumber = stoi(line);
        }

        // Read deck cards
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            string deckCards = line;
            Deck temp(deckCards, maxNumber);
            deck = temp;
        }

        // Create game manager
        GameManager gameTemp(deck);
        gameManager = gameTemp;
        // Create players
        createPLayer(myfile, line);

        // close file
        myfile.close();

        // set all the players
        gameManager.setPlayers(players);
    } else {
        cout << "Unable to open file";
    }
}

void Game::createPLayer(istream& myfile, string line) {

    int playerCounter = 0;
    while(myfile.good()){
        getline(myfile,line);
        while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
            getline (myfile,line);
        }
        string player = line;
        string delimiter = " ";
        size_t pos = 0;
        string name = "";

        while ((pos = player.find(delimiter)) != std::string::npos && name.size() == 0) {
            name = player.substr(0, pos);
            player.erase(0, pos + delimiter.length());
        }

        int playerType = 0;

        // clear blank spaces
        while ((pos = player.find(delimiter)) != std::string::npos) {
            player.erase(0, pos + delimiter.length());
        }

        // get player type
        if(player.size() > 0)
            playerType = stoi(player);

        // create player by type
        switch (playerType) {
            case 1:
                players.push_back(new PlayerType1(gameManager, name));
                break;
            case 2:
                players.push_back(new PlayerType2(gameManager, name));
                break;
            case 3:
                players.push_back(new PlayerType3(gameManager, name, playerCounter));
                break;
            case 4:
                players.push_back(new PlayerType4(gameManager, name, playerCounter));
                break;
        }

        playerCounter++;
    }

}

void Game::distributeCards(){
    vector<Player*>::iterator it;
    for( it=players.begin() ; it!=players.end() ; it++) {
        int cardsCounter = 0;
        while(cardsCounter < 7){
            Card* card = deck.fetchCard();
            (*it)->addCard(*card);
            cardsCounter++;
        }
    }
}

void Game::init(){
    Game::file_reader(configurationPath);
    Game::distributeCards();
}

void Game::play(){
//print only if printMode is on == 1

    // check if there is a winner
    //while(!gameManager.thereIsAWinner()){
    while(false){
        // count the turns
        ++turnsCounter;
        // print state
        if(printMode==1){
            cout<<"Turn "<< turnsCounter << endl;
            Game::printState();
        }
        // print next move
        int nextPlayer = (turnsCounter-1)%players.size();
        players.at(nextPlayer)->makeMove(printMode==1);
    }
}

// temporary print state
void Game::printState() {
	cout<<"Deck : "<< deck.toString() << endl;
	vector<Player *>::iterator it;
	for( it=players.begin() ; it!=players.end() ; it++) {
        cout<< (*it)->toString() << endl;
	}
}

void Game::printWinner(){
    vector<Player*> winners = gameManager.getWinners();
    if(winners.size() == 2){
        cout<<"***** The winner are: "<< winners.at(0)->getName()<< " and " << winners.at(1)->getName() <<" *****" << endl;
    } else if (winners.size() == 1){
        cout<<"***** The Winner is: "<< winners.at(0)->getName()<<" *****" << endl;
    }
}

void Game::printNumberOfTurns(){
    cout<<"Number of turns: "<< turnsCounter << endl;
}


void Game::copy(const Game& other){
    deck = other.deck;
    int i = 0;
    vector<Player*> temp = other.players;
    vector<Player*>::iterator it;
    for(it=temp.begin() ; it < temp.end(); it++, i++ ) {
        players.push_back((*it)->clone());
    }
    gameManager = other.gameManager;
}

Game& Game::operator=(const Game& other){
    if(this != &other){
        vector<Player*>::iterator it;
        for(it=players.begin() ; it < players.end(); it++) {
            delete *it;
        }

        Game::copy(other);
    }
    return *this;
}

Game::~Game(){
    vector<Player*>::iterator it;
    for(it=players.begin() ; it < players.end(); it++) {
        delete *it;
    }
}