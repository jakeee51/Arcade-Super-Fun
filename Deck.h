#pragma once

#include "card.h"
#include <vector>
#include <algorithm>
using namespace std;

#define CARDS_PER_DECK 52 //52 cards in a deck
#define NUM_OF_FACES 14 
#define NUM_OF_SUITS 4

class deck {
public:
	deck();
	~deck() { deckOfCards.clear(); currentCard = 0; } //destructor clears the deck of cards and sets currentCard to 0
	string dealCard(); //deals the cards one at a time
	void shuffleDeck(); //shuffles cards in the deck
	void fillDeck(); //fill the deck with cards
	void printDeck();
	vector <card> getDeck() { return deckOfCards; }
	string deckOfStrings();
	int getDeckSize() { return deckOfCards.size(); } //returns the size of the deck

private:
	vector<card> deckOfCards; //vector to hold the deck of cards
};



