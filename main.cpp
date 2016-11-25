#include <iostream>
#include <vector>
#include <Player.h>
#include <GameManager.h>
#include "include/Deck.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
	int N=3;//depents on input file,for this example is 3
	KeyGenerator *k=new KeyGenerator(N);
	Deck* deck = new Deck("2H KD QS QC AS KC QH 2S 2D AH AD QD AC KH 2C KS JC JS JD JH 3C 3S 3D 3H",*k);
    std::cout << "deck->getNumberOfCards()"  << std::endl;
    std::cout << deck->getNumberOfCards() << std::endl;
    std::cout << "deck->toString()"  << std::endl;
    std::cout << deck->toString() << std::endl;
    GameManager* gameManager = new GameManager(*deck);
    std::vector<Player*> players;
    PlayerType1* player1 = new PlayerType1(*gameManager, "Steph");
    player1->addCard(*(deck->fetchCard()));
    std::cout << player1->toString() << std::endl;
    player1->addCard(*(deck->fetchCard()));
    std::cout << player1->toString() << std::endl;
    std::cout << player1->getNumberOfCards() << std::endl;
    std::cout << "deck->toString()"  << std::endl;
    std::cout << deck->toString() << std::endl;
    players.push_back(player1);

    PlayerType1* player12 = new PlayerType1(*gameManager, "Steph1");
    std::cout << player12->toString() << std::endl;
    player12->addCard(*(deck->fetchCard()));
    std::cout << player12->toString() << std::endl;
    player12->addCard(*(deck->fetchCard()));
    std::cout << player12->toString() << std::endl;
    std::cout << player12->getNumberOfCards() << std::endl;
    std::cout << "deck->toString()"  << std::endl;
    std::cout << deck->toString() << std::endl;
    players.push_back(player12);

    gameManager->setPlayers(players);
    //getTotalOfPlayers
    std::cout << gameManager->getTotalOfPlayers() << std::endl;

    //getPlayerWithMaxCards
    std::cout << gameManager->getPlayerWithMaxCards()->toString() << std::endl;
    std::cout << gameManager->getPlayerWithMinCards()->toString() << std::endl;
    std::cout << gameManager->getPlayerByPosition(1)->toString() << std::endl;
    std::cout << gameManager->getPlayerByPosition(0)->toString() << std::endl;
    std::cout << gameManager->getPlayerWithMaxCards(*player12)->toString() << std::endl;
    std::cout << gameManager->getPlayerWithMinCards(*player1)->toString() << std::endl;
    std::cout << gameManager->getCardFromDeck()->toString() << std::endl;

    return 0;
}