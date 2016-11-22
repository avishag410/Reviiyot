#ifndef KeyGenerator_H_
#define KeyGenerator_H_

#include <iostream>
using namespace std;

class KeyGenerator
{
	private:
		int N;
	public:
		KeyGenerator(int n);
		int generate(string cardString);
};

#endif