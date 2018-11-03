#include "card.h"
#include <iostream>
using namespace std;


card::card() {
	nameFace = "";
	nameSuit = "";
	value = "";
}

/* *********************************************************************
Function Name: Overloaded construtor of the card class
Purpose: To create a card of different suit and face
Parameters: int cardFace, int cardSuit
Local Variables: None
Return Value: 
Algorithm:
1) Uses a switch statement to assign the card a cardFace value and cardSuit value
2) Combines the nameFace and nameSuit to create a card value
Assistance Received: None
********************************************************************* */
card::card(int cardFace, int cardSuit) {

	switch(cardFace) {
	case 1:
		nameFace = "A";
		break;
	case 2:
		nameFace = "2";
		break;
	case 3:
		nameFace = "3";
		break;
	case 4:
		nameFace = "4";
		break;
	case 5:
		nameFace = "5";
		break;
	case 6:
		nameFace = "6";
		break;
	case 7:
		nameFace = "7";
		break;
	case 8:
		nameFace = "8";
		break;
	case 9:
		nameFace = "9";
		break;
	case 10:
		nameFace = "X";
		break;
	case 11:
		nameFace = "J";
		break;
	case 12:
		nameFace = "Q";
		break;
	case 13:
		nameFace = "K";
		break;
	/* case 14:
		nameFace = "A";
		break; */
	default:
		break;
	}

	switch (cardSuit) {
	case 0:
		nameSuit = "S"; //spades
		break;
	case 1:
		nameSuit = "C"; //clubs
		break;
	case 2:
		nameSuit = "H"; //hearts
		break;
	case 3:
		nameSuit = "D"; //diamonds
		break;
	default:
		break;
	}

	value = nameSuit + nameFace;
}

// print() function prints the card (for testing purposes)
void card::printCard() {
	cout << nameSuit << nameFace << endl;
}


card::~card()
{
}

