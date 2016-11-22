#include <iostream>
#include "include/Deck.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Deck* deck = new Deck("2H KD QS QC AS KC QH 2S 2D AH AD QD AC KH 2C KS JC JS JD JH 3C 3S 3D 3H");
    deck->toString();
    std::cout << "deck->getNumberOfCards()"  << std::endl;
    std::cout << deck->getNumberOfCards() << std::endl;
    Card* card = deck->fetchCard();
    while(card != NULL){
        std::cout << "card->get_key()" << std::endl;
        std::cout << card->get_key() << std::endl;
        std::cout << "card->get_shape() " << std::endl;
        std::cout << card->get_shape() << std::endl;
        std::cout << "card->toString() " << std::endl;
        std::cout << card->toString() << std::endl;
        card = deck->fetchCard();

    }

    std::cout << "deck->getNumberOfCards()"  << std::endl;
    std::cout << deck->getNumberOfCards() << std::endl;

    return 0;
}