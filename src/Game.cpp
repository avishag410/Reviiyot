#include <iostream>
#include <Player.h>
#include <Deck.h>
#include <Game.h>
#include <fstream>
using namespace std;

Game::Game(char* configurationFile):players(), deck(""){
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
            int mode = stoi(line);
            cout << mode << endl;
        }

        // Read max number
        if(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            int maxNumber = stoi(line);
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
            //deck = *(new Deck(deckCards));
        }

        // Create players
        while(myfile.good()){
            getline(myfile,line);
            while (myfile.good() && (line.size() == 0 || line.find("#") == 0)) {
                getline (myfile,line);
            }
            string player = line;
            cout << player << endl;
            //deck = *(new Deck(deckCards));
        }

        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}

void Game::stream_reader(istream& stream, string line)
{
    getline (stream,line);
    if (line.size() == 0 || line.find("#") == 0) {
        //getline (stream,line);
        cout << "empty44  " << endl;
    } else{
        cout << line << endl;
    }
}

void Game::init(){

}

void Game::play(){

}

void Game::printState(){

}

void Game::printWinner(){

}

void Game::printNumberOfTurns(){

}