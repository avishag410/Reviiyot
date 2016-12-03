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
	//cout << "[DEBUG] Game::file_reader :" << endl;
    if (myfile.is_open())
    {
        // Read mode
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            printMode = stoi(line);
			//cout << "Debug: printMode = " << printMode << endl;
        }

        // Read max number
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            maxNumber = stoi(line);
			//cout << "Debug: maxNumber = " << maxNumber << endl;
        }

        // Read deck cards
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
			
            string deckCards = line;
             Deck temp(deckCards, maxNumber);
			 deck=temp;
            
			//cout << "Debug: Game.cpp :deckCards = " << endl;
        }
		
        // Create game manager
        GameManager gameTemp(deck);
        gameManager = gameTemp;
        // Create players
        createPlayer(myfile, line);

        // close file
        myfile.close();

        // set all the players
        gameManager.setPlayers(players);
		//cout << "Debug: Game.cpp : SetPlayers = " << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
}

void Game::createPlayer(istream& myfile, string line) {

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
		//cout << "Debug: player = " << player << endl;
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
        if(player.size() > 0 && !player.empty() && player.find('\n') == std::string::npos && player.find('\0') == std::string::npos)
            playerType = stoi(player);

        // create player by type
		Player *tempP;
        switch (playerType) {
            case 1:
				tempP= new PlayerType1(gameManager, name);
				tempP->setCardCounter(maxNumber);
                players.push_back(tempP);
                break;
            case 2:
                tempP = new PlayerType2(gameManager, name);
				tempP->setCardCounter(maxNumber);
                players.push_back(tempP);
                break;
            case 3:
                tempP = new PlayerType3(gameManager, name, playerCounter);
				tempP->setCardCounter(maxNumber);
                players.push_back(tempP);
                break;
            case 4:
                tempP = new PlayerType4(gameManager, name, playerCounter);
				tempP->setCardCounter(maxNumber);
                players.push_back(tempP);
                break;
			default:
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
    while(!gameManager.thereIsAWinner()){
        // count the turns
        ++turnsCounter;
        // print state
        if(printMode==1){
            cout<<"Turn "<< turnsCounter << endl;
            Game::printState();
        }
        // print next move
        int nextPlayer = (turnsCounter-1)%players.size();
		//cout << "Debug: Game: play :next player"<< nextPlayer << endl;
        players.at(nextPlayer)->makeMove(printMode==1);
		

    }
	
}

// temporary print state
void Game::printState() {
	cout<<"Deck: "<< deck.toString() << endl;
	vector<Player *>::iterator it;
	for( it=players.begin() ; it!=players.end() ; it++) {
        cout<< (*it)->toString() << endl;
	}
}

void Game::printWinner(){
    vector<Player*> winners = gameManager.getWinners();
    if(winners.size() == 2){
        cout<<"***** The winners are: "<< winners.at(0)->getName()<< " and " << winners.at(1)->getName() <<" *****" << endl;
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

Game::~Game()
{
    vector<Player*>::iterator it;
    for(it=players.begin() ; it < players.end(); it++) {
        delete(*it);
    }

}