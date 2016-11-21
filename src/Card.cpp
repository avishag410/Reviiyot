#include<iostream>
#include<Card.h>

Shape Card::get_shape() const
{
	return shape;
}

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
