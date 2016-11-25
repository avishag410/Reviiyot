#include <iostream>
#include <vector>
#include <Deck.h>
#include <Utils.h>
#include <Card.h>

using namespace Cards;
using namespace std;

Deck::Deck(string cards):cards(){
    if(cards.size() > 0) {
        string delimiter = " ";
        size_t pos = 0;
        string token;

        // insert the new cards at the beginning, so the fetch card is from the end
        while ((pos = cards.find(delimiter)) != std::string::npos) {
            std::cout << "enter deck while" << std::endl;
            token = cards.substr(0, pos);
            std::cout << token << std::endl;
            Deck::insertCard(token);
            cards.erase(0, pos + delimiter.length());
        }
        Deck::insertCard(cards);
    }
}

void Deck::insertCard(string cardStr){
    Card *card;
    // create new card with a smart pointer
    if(Utils::isNumericCard(cardStr)){
        card = new NumericCard(cardStr);
    } else {
        card = new FigureCard(cardStr);
    }
    Deck::cards.insert(Deck::cards.begin(), card);
}

// remember that calling this method we lost a reference to a card and someone else needs to release its memory
Card* Deck::fetchCard(){
    if( Deck::cards.size() > 0){
        Card* result = Deck::cards.back();
        Deck::cards.pop_back();
        return result;
    }
    return NULL;
}
int Deck::getNumberOfCards(){
    return Deck::cards.size();
}
string Deck::toString(){
    string result = "";
    vector<Card*>::reverse_iterator it;
    for(it=Deck::cards.rbegin() ; it < Deck::cards.rend(); it++ ) {
        // found nth element..print and break.
        if(result.length() > 0)
            result+= " ";
        result += (*it)->toString();
    }

    return result;
}

Deck::~Deck(){
    vector<Card*>::iterator it;
    for(it=cards.begin(); it < cards.end(); it++ ) {
        delete *it;
    }
}