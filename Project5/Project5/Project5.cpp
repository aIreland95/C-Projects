// Project5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib> // used for random number generation
#include <ctime>
#define DECK_SIZE 52 // used for defining a constant size for a deck of cards
using namespace std;

// Aaron Ireland
// Project 5
// October 24, 2018

class Card { // class for an individual playing card

public:

	Card() {} // blank Card constructor

	Card(int v, string s) { // Card constructor, sets value and suit to v and s respectively

		value = v;
		suit = s;
	}

	string getName() { // getName function, simply returns the name of the card

		switch (value) {

		case(11): // value is 11, name returns with Jack
			name = ("Jack of " + suit);
			return name;
			break;

		case(12): // value is 12, name returns with Queen
			name = ("Queen of " + suit);
			return name;
			break;

		case(13): // value is 13, name returns with King
			name = ("King of " + suit);
			return name;
			break;

		case(14): // value is 14, name returns as Ace
			name = ("Ace of " + suit);
			return name;
			break;

		default: // value is between 2 and 10, returns name with the value changed to a string
			name = (to_string(value) + " of " + suit);
			return name;
			break;
		}
	}

	bool operator>(const Card& c) { // overloading the > operator

		return value > c.value;  // returns true if this->value is greater
	}

	bool operator<(const Card& c) { // overloading the < operator

		return value < c.value; // returns true if this->value is lower
	}

	bool operator==(const Card& c) { // overloading the == operator

		return value == c.value; // returns true if card values are equal
	}

private:

	string suit; // one of four suits for a card
	int value; // one of 13 values for a card
	string name; // full name of a card
};

class Deck { // class for the entire deck of cards

public:

	Deck() { // default constructor
	
		// arrays used for defining card suits and values
		int values[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
		string suits[] = { "Spades", "Hearts", "Clubs", "Diamonds" };

		// creates a new deck, sets the current card to zero. Current used for incremental purposes
		deck = new Card[DECK_SIZE];
		current = 0;

		for (int i = 0; i < DECK_SIZE; i++) {

			deck[i] = Card(values[i % 13], suits[i / 13]); // sets each card to a specific value and suit using random number generator
		}

		round++; // increments round after all cards have been compared

		if (round == 5) { // if 5 rounds have been completed, deleteDeck() is called

			deleteDeck(); // calling deleteDeck() here allows the deck to remain in scope for proper deletion
		}
	}

	void Shuffle() { // shuffle function, utilized when all 52 cards have been compared

		current = 0; // resets the current card to zero

		for (int i = 0; i < DECK_SIZE; i++) { // for loop used for shuffling cards in the deck

			int j = (rand() + time(0)) % DECK_SIZE;

			Card temp = deck[i]; // temporary card variable, used for shuffling purposes
			deck[i] = deck[j];
			deck[j] = temp;
		}
	}

	Card* Draw() { // Draw function, returns a card while the deck still contains cards, or current is less than DECK_SIZE 

		if (current >= DECK_SIZE) { // shuffles the deck, returns NULL if the deck is empty, or current is incremented past the DECK_SIZE
			
				Shuffle();
				return NULL;
		}
		else if (current < DECK_SIZE) { // returns a card and increments the current card increment counter
			
			return &deck[current++]; // returns the deck ponter with the incremented current card, dereferenced
		}
	}

	void deleteDeck() { // function for deleting the deck

		delete[] deck;
		deck = NULL;
	}

private:

	Card *deck; // card pointer variable
	int current; // variable for the current card
	int round = 0; // increment variable, used for delete purposes
};

int main()
{
	// this is the deck of cards that will be used the entire time
	Deck deck;

	// Do 5 rounds of testing.  Each round of testing does the following:
	//   1.  Shuffle the deck.
	//   2.  Draw 2 cards from the deck.
	//   3.  Compare the 2 cards and print which is better, or if they are equal.
	//   4.  Keep doing this until the deck is empty.
	for (int i = 0; i < 5; ++i) {
		std::cout << "ROUND " << i + 1 << std::endl;
		deck.Shuffle();

		Card* card1 = deck.Draw();
		Card* card2 = deck.Draw();

		int count = 0;
		while ((card1 != NULL) && (card2 != NULL)) {
			std::cout << "  Play # " << ++count << ":  ";
			if (*card1 == *card2) {
				std::cout << card1->getName() << " and " << card2->getName() << " are equal." << std::endl;
			}
			else if (*card1 > *card2) {
				std::cout << card1->getName() << " is better than " << card2->getName() << std::endl;
			}
			else if (*card1 < *card2) {
				std::cout << card1->getName() << " is not as good as " << card2->getName() << std::endl;
			}
			else {
				std::cout << "ERROR - something went wrong with comparison of " << card1->getName() << " and " << card2->getName() << std::endl;
			}

			card1 = deck.Draw();
			card2 = deck.Draw();
		}
	}
}