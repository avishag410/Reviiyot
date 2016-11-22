#ifndef Utils_H
#define Utils_H

#include<iostream>
#include<Card.h>
using namespace std;
using namespace Cards;

class Utils
{
public:
	static Cards::Shape parseShape(string shapeLetter);
};
#endif