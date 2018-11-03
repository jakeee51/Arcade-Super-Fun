#pragma once

#include <iostream>
#include <string>

using namespace std;

// suit: H, C, D, S
// rank: A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K

class card
{
public:
	card();
	card(int cardFace, int cardSuit);
	~card();
	string getValue() { return value; }
	
	void printCard();

private:
	string nameFace;
	string nameSuit;
	string value;
};
