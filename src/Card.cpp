#include<iostream>
#include<Card.h>
#include "../include/Card.h"

using namespace std;
using namespace Cards;

int Card::get_key() 
{
	//TODO:exceptions?
	return 10; // Card::key;
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

void Card::set_shape(Cards::Shape nShape){
	shape = nShape;
}

Cards::Shape Card::get_shape(){
	return shape;
}

Card::~Card(void){

}

