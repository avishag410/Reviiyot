#include<iostream>
#include<Card.h>
using namespace std;
/*
	NumericClass.cpp
*/

NumericCard::NumericCard(string cardStr)
{
	valueString=cardStr;
}

int NumericCard::get_number() const
{
	return this->number;
}

