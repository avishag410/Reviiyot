#include <iostream>
#include <vector>
#include "include/Player.h"
#include "include/GameManager.h"
#include "include/Deck.h"
#include "include/Game.h"

using namespace std;
int main()
{	int i;
	int N=3;//depents on input file,for this example is 3
	Deck* deck = new Deck("2H 2D QS 2C AS KC KD AH AD QD AC KH KS JC JS JD JH 3C 3S 3D",N);
	GameManager* gameManager = new GameManager(*deck);
    std::vector<Player*> players;
    PlayerType1* player1 = new PlayerType1(*gameManager, "Avishag");
	
	for(i = 0; i < 20; i++)
	{
		Card * tempCard = deck->fetchCard();
		player1->addCard(*tempCard);
		cout << "Added card - " << tempCard->toString() << endl;
	
	}
	
	//cout<<player1->checkForNumericSerias().first<<endl;
	cout<<player1->toString()<<endl;
	return 0;
}

