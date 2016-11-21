#ifndef Utils_H
#define Utils_H

#include<iostream>
using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Utils
{
public:
	static Shape parseShape(string shapeLetter);
};
#endif