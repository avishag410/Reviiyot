#include <iostream>
#include <vector>
#include <Deck.h>
#include <Utils.h>
#include <Card.h>

using namespace Cards;
using namespace std;


Deck::Deck(string cards,int HighestNum):cards(){
    if(cards.size() > 0) {
        string delimiter = " ";
        size_t pos = 0;
        string token;

        // insert the new cards at the beginning, so the fetch card is from the end
        while ((pos = cards.find(delimiter)) != std::string::npos) {
            token = cards.substr(0, pos);
            if(token.size() > 0){
                Deck::insertCard(token, HighestNum);
            }
            cards.erase(0, pos + delimiter.length());
        }
        if(cards.size() > 0)
            Deck::insertCard(cards, HighestNum);
    }
}

Deck::Deck(const Deck& other):cards(){
    Deck::copy(other);
}

void Deck::insertCard(string cardStr,int HighestNum){
    Card *card;
    // create new card with a smart pointer
    if(Utils::isNumericCard(cardStr)){
        card = new NumericCard(cardStr);
    } else {
        card = new FigureCard(cardStr);
    }
	int key=Utils::generateKey(cardStr,HighestNum);
	card->set_key(key);
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

void Deck::copy(const Deck& other){

    vector<Card*> temp = other.cards;
    vector<Card*>::iterator it;
    for(it=temp.begin(); it < temp.end(); it++ ) {
        cards.push_back((*it)->clone());
    }
	
}

Deck& Deck::operator=(const Deck& other){
    if(this != &other){
        vector<Card*>::iterator it;
        for(it=cards.begin() ; it < cards.end(); it++) {
            delete(*it);
        }

        Deck::copy(other);
		
    }
    return *this;
}

Deck::~Deck()
{
    vector<Card*>::iterator it;
    for(it=cards.begin(); it < cards.end(); it++ ) {
        delete(*it);
    }
	
}