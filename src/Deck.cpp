#include <iostream>
#include <vector>
#include <Deck.h>
#include <Utils.h>
#include <Card.h>

using namespace Cards;
using namespace std;

Deck::Deck(string cards)
{
    string delimiter = " ";
    size_t pos = 0;
    string token;

    // insert the new cards at the beginning, so the fetch card is from the end
    while ((pos = cards.find(delimiter)) != std::string::npos) {
        token = cards.substr(0, pos);
        cout << token << endl;

        Deck::insertCard(token);

        cards.erase(0, pos + delimiter.length());
    }
    cout << cards << endl;
    Deck::insertCard(cards);
}

void Deck::insertCard(string cardStr){
    Card *card;
    // create new card with a smart pointer
    if(Utils::isNumericCard(cardStr)){
        cout << "is numeric" << endl;
        card = new NumericCard(cardStr);
    } else {
        cout << "is figure" << endl;
        card = new FigureCard(cardStr);
    }

    Deck::cards.insert(Deck::cards.begin(), card);
}

Card* Deck::fetchCard(){

    // TODO copy constructor or operator = then will not be null reference
    Card* result = Deck::cards[Deck::cards.size()-1];
    Deck::cards.pop_back();

    return result;
}
int Deck::getNumberOfCards(){
    return Deck::cards.size();
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