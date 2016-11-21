#ifndef KeyGenerator_H_
#define KeyGenerator_H_

#include <iostream>
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

class KeyGenerator
{
	private:
		int N;
	public:
		KeyGenerator(int n);
		int generate(string cardString);
};

#endif