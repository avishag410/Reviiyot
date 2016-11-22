#include<iostream>
#include<Card.h>

using namespace Cards;

int Card::get_key() const
{
	//TODO:exceptions?
	return key;
}

void Card::set_key(int key)
{
	//TODO:exceptions?
	this->key=key;
}

int Card::compare(Card &otherCard)
{
	return ( this->get_key() ) - ( otherCard.get_key() );
}

void set_shape(Cards::Shape nShape){

}

Card::~Card(void){

}