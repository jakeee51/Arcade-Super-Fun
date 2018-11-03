#include "deck.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Constructor fills a vector with a deck of cards and shuffles it using the fillDeck method
deck::deck()
{
	currentCard = 0;
}

/* *********************************************************************
Function Name: fillDeck
Purpose: To fill the vector deckOfCards
Parameters: None
Local Variables: None
Return Value: None, void function
Algorithm:
1) Nested for loop iterates through i and j
2) Creates an object from the card class using the overloaded constructor of the card class
3) Put card in the vector 
4) Increment currentCard and check if currentCard is == to 52 cards
Assistance Received: None
********************************************************************* */

void deck::fillDeck() {

	for (int i = 1; i < NUM_OF_FACES; i++) {
		for (int j = 0; j < NUM_OF_SUITS; j++) {

			// creates objects of the card class which uses the nested for loop to fill the deck 
			card card(i, j); 

			// puts card into vector
			deckOfCards.push_back(card); 

			// increments card count
			currentCard++;

			// if statement to make sure if current card is equal to 
			if (currentCard == CARDS_PER_DECK) { 
				break;
			}
		}
	}
} 


/* *********************************************************************
Function Name: printDeck
Purpose: To print the vector deckOfCards
Parameters: None
Return Value: None
Assistance Received: None
********************************************************************* */
void deck::printDeck() {
	// sizeOfDeck variable holds the size of the deckOfCards vector
	int sizeOfDeck = deckOfCards.size();

	cout << "Deck: ";
	// if statment to check if the sizeOfDeck is == 0
	if (sizeOfDeck == 0) {
		cout << "No cards in the deck" << endl;
	}

	// else statement to print the deck if size is > 0
	else {

		// for loop iterates over the deckOfCards vector and calls the getValue function from the card class to return the value and print it out
		for (size_t i = 0; i < sizeOfDeck; i++) {
			cout << deckOfCards[i].getValue() << " ";
		}

		cout << endl;

	}
}


/* *********************************************************************
Function Name: deckOfStrings
Purpose: To create a string of the whole deckOfCards vector
Parameters: None
Return Value: string deckString, holds the whole deckOfCards vector as one string
Assistance Received: None
********************************************************************* */
string deck::deckOfStrings() {
	string cardValue;
	string deckString;

	for (size_t i = 0; i < deckOfCards.size(); i++) {
		cardValue = deckOfCards[i].getValue();
		deckString += cardValue + " ";
	}

	return deckString;
}


/* *********************************************************************
Function Name: shuffleDeck
Purpose: To shuffle the deckOfCards vector
Parameters: None
Local Variables: int randNum, an integer used to hold a random number between 10 and 99
Return Value: None, void function
Algorithm:
1) initialize an int using the random number generator to get an integer between 10 and 99
2) Using a for loop, call the random_shuffle function as many times as the value of randNum
Assistance Received: None
********************************************************************* */
void deck::shuffleDeck() {

	// seeding srand
	srand(time(NULL));

	// declaring randNum which will hold a number between 10 and 99
	int randNum = 10 + rand() % (99 - 10 + 1); 

	// for loop using randNum to shuffle the cards howevery many times the value of randNum is
	for (int i = 0; i < randNum; i++) {
		// shuffle function that is available to use by vector
		random_shuffle(deckOfCards.begin(), deckOfCards.end()); 
	}
}

/* *********************************************************************
Function Name: dealCard
Purpose: To deal a card one at a time
Parameters: None
Local Variables: card temp, an object of the card class that will hold the card from deckOfCards
				 cardVal, string data type that will hold the value of the card to return
Return Value: cardVal, string that holds the value of a card
Algorithm:
1) Get a card from the back of the deckOfCards vector
2) Delete the last element of the vector
3) Get the value of the card 
4) Return the value of the card
Assistance Received: None
********************************************************************* */
string deck::dealCard() {

		// creates a card object, temp, and copies a card object from deckOfCards a certain index	
		card temp = deckOfCards[currentCard - 1];
		// decrements currentCard
		currentCard--;
		// deletes last element of the deckOfCards vector
		deckOfCards.pop_back();
		// creates string data type where the value of the card object temp is assigned to it
		string cardVal = temp.getValue();
		// returns cardVal
		return cardVal;

}
