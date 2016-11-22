#include <iostream>
#include <Deck.h>
#include "include/Deck.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Deck* deck = new Deck("2H KD QS QC AS KC QH 2S 2D AH AD QD AC KH 2C KS JC JS JD JH 3C 3S 3D 3H");
    deck->toString();
    return 0;
}