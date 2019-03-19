// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Aaron Ireland
// Project 1
// September 14, 2018

// helper function: displays horizontal lines based on the number of columns
int horizontal(int c) {

	switch (c) {
	case 6:
		cout << "\n-------------------------" << endl;
		break;
	case 8:
		cout << "\n---------------------------------" << endl;
		break;
	case 5:
		cout << "\n---------------------" << endl;
		break;
	}
	return 0;
}

// helper function: displays vertical lines based on the number of columns
int vertical(int c) {

	cout << "|   ";
	return 0;
}

// helper function: displays numbers along the bottom of the board
int numberDisplay(int c) {

	for (int i = 1; i <= c; i++) {
		cout << "  " << i << " ";
	}
	cout << "\n\n";
	return 0;
}

// printBoard function: uses rows and columns as arguments by value, displays board
int printBoard(int rows, int columns) {

	horizontal(columns); // helper function: called outside of loop to place single horizontal line

	for (int y = 0; y < rows; y++) { // for loops used for displaying the board

		for (int x = 0; x <= columns; x++) {

			vertical(columns); // helper function: displays vertical lines for each column
		}

		horizontal(columns); // helper function: called within for loop to display multiple horizontal lines
	}
	
	numberDisplay(columns); // helper function: called outside of for loops to display numbers at bottom of board
	return 0;
}

int main()
{
	cout << "Welcome to Connect 4!\n"; // initial message for user, introduces the game

	printBoard(6, 6); // printBoard function called multiple times with different argument values
	printBoard(6, 8);
	printBoard(7, 5);

	cout << "Scroll up to view the different board layouts. User interaction and game data will be added next.\n";
    return 0;
}