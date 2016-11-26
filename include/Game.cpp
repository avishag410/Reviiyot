#include <iostream>
#include <Player.h>
#include <Deck.h>
#include <Game.h>
#include <fstream>
using namespace std;

Game::Game(char* configurationFile):players(), deck("", 0), maxNumber(0), printMode(0){
    Game::file_reader(configurationFile);
}

void Game::file_reader(string path)
{
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

        // Create players
        createPLayer(myfile, line);
        myfile.close();
    } else {
        cout << "Unable to open file";
    }
}

void Game::createPLayer(istream& myfile, string line)
{
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

        while ((pos = player.find(delimiter)) != std::string::npos && name.size() > 0) {
            name = player.substr(0, pos);
            player.erase(0, pos + delimiter.length());
        }

        int playerType = 0;

        while ((pos = player.find(delimiter)) != std::string::npos && playerType == 0) {
            string type = player.substr(0, pos);
            playerType = stoi(type);
            player.erase(0, pos + delimiter.length());
        }

        // create player by type

    }

}

void Game::init(){

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