#include<iostream>
#include<Card.h>
#include "../include/Card.h"

using namespace std;
using namespace Cards;

Card::Card(Cards::Shape _shape, string _value):shape(_shape),key(-1) , valueString(_value) {}

Card::Card(const Card &rhs):shape(rhs.shape), key(rhs.key), valueString(rhs.valueString) {}

int Card::get_key() const
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

void Card::set_shape(Cards::Shape nShape)
{
	shape = nShape;
}

Cards::Shape Card::get_shape() const
{
	return shape;
}

Card::~Card()
{

}

