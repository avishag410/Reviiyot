#include <iostream>
#include <Player.h>
#include <Deck.h>
#include <Game.h>
#include <GameManager.h>
#include <fstream>
using namespace std;

Game::Game(char* configurationFile)
        :players(), deck("", 0), maxNumber(0), printMode(0), configurationPath(configurationFile), gameManager(deck){
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
            cout << printMode << endl;
        }

        // Read max number
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            maxNumber = stoi(line);
            cout << maxNumber << endl;
        }

        // Read deck cards
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            string deckCards = line;
            cout << deckCards << endl;
            deck = *(new Deck(deckCards, maxNumber));
            cout << deck.toString() << endl;
        }
        // Create game manager
        gameManager = *(new GameManager(deck));
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
        cout << player << endl;

        string delimiter = " ";
        size_t pos = 0;
        string name = "";

        while ((pos = player.find(delimiter)) != std::string::npos && name.size() == 0) {
            name = player.substr(0, pos);
            player.erase(0, pos + delimiter.length());
        }

        int playerType = 0;

        while ((pos = player.find(delimiter)) != std::string::npos && playerType == 0) {
            string type = player.substr(0, pos);
            playerType = stoi(type);
            player.erase(0, pos + delimiter.length());
        }

        Player* newPlayer;
        // create player by type
        switch (playerType) {
            case 1:
                newPlayer = new PlayerType1(gameManager, name);
                break;
            case 2:
                newPlayer = new PlayerType2(gameManager, name);
                break;
            case 3:
                newPlayer = new PlayerType3(gameManager, name, playerCounter);
                break;
            case 4:
                newPlayer = new PlayerType4(gameManager, name, playerCounter);
                break;
        }

        players.push_back(newPlayer);
        playerCounter++;
    }

}
void Game::shuffleCards()
{
	
	vector<Player*>::iterator it;
	
	for(it=players.begin();it!=players.end();it++)
	{
		for(int i=0;i<7;i++)
		{
			(*it)->addCard(*(deck.fetchCard()));
		}
	}
}
void Game::init(){
    Game::file_reader(configurationPath);
	Game::shuffleCards();
}

void Game::play(){

}

void Game::printState()
{

	cout<<"Deck : "<<deck.toString()<<endl;

	vector<Player *>::iterator it;
	for( it=players.begin() ; it!=players.end() ; it++)
	{
		cout<<(*it)->toString()<<endl;
	}
	
}

void Game::printWinner(){

}

void Game::printNumberOfTurns(){

}