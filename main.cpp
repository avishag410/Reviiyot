#include <iostream>
#include <vector>
#include <Player.h>
#include <GameManager.h>
#include "include/Deck.h"
#include "Game.h"


int main(int argc,char **argv) 
{
	char* configurationFile = argv[1];
    Game game =Game(configurationFile);
    game.init();
    game.printState();
    Game initializedGame = game;
    initializedGame.printState();
	return 0;
}