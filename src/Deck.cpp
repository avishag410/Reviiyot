#include <iostream>
#include <vector>
#include <Deck.h>


Deck::Deck(std::string cards)
{
//    std::string s = "scott>=tiger>=mushroom";
//    std::string delimiter = ">=";
//
//    size_t pos = 0;
//    std::string token;
//    while ((pos = s.find(delimiter)) != std::string::npos) {
//        token = s.substr(0, pos);
//        std::cout << token << std::endl;
//        s.erase(0, pos + delimiter.length());
//    }
//    std::cout << s << std::endl;
}

// when the constructor is called with the string of cards, we will split it, then we will get the total of cards
// then we can initialize the vector with a size and run reverse iterators, so when we need to fetch card, we will fetch
// the one from the top. also if when need to print the vector, we will run reverse iterator ;)
Deck::Card* fetchCard(){

    // TODO copy constructor or operator = then will not be null reference
    Card* result = Deck::cards[Deck::cards.size-1];
    Deck::cards.pop_back();

    return result;
}
int Deck::getNumberOfCards(){
    return Deck::cards.size;
}
string Deck::toString(){
    string result = "";
//    for (std::vector<int>::iterator it = cards.begin(); it != cards.end(); ++it)
//        result += *it.toString();

    return result;
}

Deck::~Deck(){
   // delete cards;
}