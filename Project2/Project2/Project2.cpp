// Project2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Aaron Ireland
// Project 2
// September 21, 2018

// global variables

char** gGameBoard; //pointer to a pointer, used for creating a dynamic 2D array
int rows = 0; // rows and columns used for board dimensions
int columns = 0;
int win = 0; // determines if a win or tie has occurred (0 means to continue, 1 end gameplay)

// helper function: asks user for the size of the board, specified with rows and columns
void setBoardSize() {

	while (rows <= 3 || rows >= 13) { // asks user for number of columns

		cout << "\nPlease enter the number of rows on the game board (4-12): ";
		cin >> rows;

		if (rows <= 3 || rows >= 13) { // error check, asks for rows again
			cout << "\nYou have entered an invalid number of rows." << endl;
		}
	}

	while (columns <= 3 || columns >= 13) { // asks user for number of columns

		cout << "\nPlease enter the number of columns on the game board (4-12): ";
		cin >> columns;

		if (columns <= 3 || columns >= 13) { // error check, asks for columns again
			cout << "\nYou have entered an invalid number of columns." << endl;
		}
	}
}

// helper function: creates the game board using the parameters provided by the user
void createGameBoard() {

	gGameBoard = new char*[rows]; // creates a new pointer based on the rows specified

	for (int i = 0; i < rows; ++i) { 

		gGameBoard[i] = new char[columns]; // for each row, creates columns
	}
}

// helper function: initializes the game board, setting each array element to a value of ' '
void initBoard() {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			gGameBoard[i][j] = ' '; // sets each array element to ' '
		}
	}
}

// helper function: displays horizontal lines based on the number of columns
void horizontal() {

	switch (columns) { // based on the columns selected, the horizontal lines will vary in size
	case 4: cout << "\n-----------------" << endl;
		break;
	case 5: cout << "\n---------------------" << endl;
		break;
	case 6: cout << "\n-------------------------" << endl;
		break;
	case 7: cout << "\n-----------------------------" << endl;
		break;
	case 8: cout << "\n---------------------------------" << endl;
		break;
	case 9: cout << "\n-------------------------------------" << endl;
		break;
	case 10: cout << "\n-----------------------------------------" << endl;
		break;
	case 11: cout << "\n---------------------------------------------" << endl;
		break;
	case 12: cout << "\n-------------------------------------------------" << endl;
		break;
	}
}

// helper function: displays numbers along the bottom of the board
void numberDisplay() {

	for (int i = 1; i <= columns; i++) {
		cout << "  " << i << " ";
	}
	cout << "\n\n";
}

// printBoard function: uses rows and columns as arguments by value, displays board
void printBoard() {

	horizontal(); // helper function: called outside of loop to place single horizontal line

	for (int i = 0; i < rows; i++) { // for loops used for displaying the board

		for (int j = 0; j <= columns; j++) {

			cout << "| " << gGameBoard[i][j] << " "; // places each array element value into the game board
		}

		horizontal(); // helper function: called within for loop to display multiple horizontal lines
	}

	numberDisplay(); // helper function: called outside of for loops to display numbers at bottom of board
}

// ffunction used to check if a player connects four pieces horizontally
void horizontalCheck(char p) {

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < columns; j++) {

			if (gGameBoard[i][j] == p && // major if statement, compares elements, keeps rows fixed
				gGameBoard[i][j + 1] == p &&
				gGameBoard[i][j + 2] == p &&
				gGameBoard[i][j + 3] == p) {
				cout << "Player " << p << " is the winner!\n"; // outputs the winner
				win = 1;
			}
		}
	}
}

// function used to check if a player connects four pieces vertically
void verticalCheck(char p) {

	for (int j = 0; j < columns; j++) {

		for (int i = (rows - 1); i > 0; i--) {

			if (gGameBoard[i][j] == p && // major if statement, compares elements, keeps columns fixed
				gGameBoard[i - 1][j] == p &&
				gGameBoard[i - 2][j] == p &&
				gGameBoard[i - 3][j] == p) {
				cout << "Player " << p << " is the winner!\n"; // outputs the winner
				win = 1;
			}
		}
	}
}

// function used to check if a player connects four pieces diagonally (right)
void diagonalCheck1(char p) {

	for (int i = 0; i < (columns - 3); i++) {

		for (int j = 0; j < (rows - 3); j++) {

			if (gGameBoard[i][j] == p && // major if statement, compares elements, keeps columns fixed
				gGameBoard[i + 1][j + 1] == p &&
				gGameBoard[i + 2][j + 2] == p &&
				gGameBoard[i + 3][j + 3] == p) {
				cout << "Player " << p << " is the winner!\n"; // outputs the winner
				win = 1;
			}
		}
	}
}

// function used to check if a player connects four pieces diagonally (left)
void diagonalCheck2(char p) {
	
	int i, j;

	for (i = 0; i < (columns - 3); i++) {

		for (j = 0; j < (rows - 3); j++) {

			if (gGameBoard[i + 3][j] == p && // major if statement, compares elements, keeps columns fixed
				gGameBoard[i + 2][j + 1] == p &&
				gGameBoard[i + 1][j + 2] == p &&
				gGameBoard[i][j + 3] == p) {
				cout << "Player " << p << " is the winner!\n"; // outputs the winner
				win = 1;
			}
		}
	}
}

// function that checks for a winner (four in a row) horizontally, vertically, and diagonally
void checkWin(char p) {

	horizontalCheck(p); // calls each directional check function for a win condition
	verticalCheck(p);
	diagonalCheck1(p);
	diagonalCheck2(p);
}


// function that checks for a tie (all columns full)
void checkTie() {

	int i = 0;
	int count = 0; // count used to determine how many top row sections are filled

	for (int j = 0; j < columns; j++) {

		if (gGameBoard[i][j] != ' ') {
				
			count++; // increments by one for each filled space

			if (count == columns) { // tie occurs when count is equal to the number of columns
				cout << "It's a tie. No more moves are available.\n";
				win = 1;
			}
		}
	}
}


// function that executes the players turn
void playerGo(char p) {

	bool valid = false; // error check variable
	int select; // player's column choice

	while (valid == false) {

		cout << "Player " << p << ", select a column to place your game piece (" << p << "): ";
		cin >> select;

		if (select < 1 || select > columns) { // player inputs a column that does not exist
			cout << "\nYou have input an invalid column. Please try again.\n\n";
			valid = false;
		}
		else {

			for (int i = 1; i <= rows; i++) { // player selects a valid column, only executes once, and places piece at bottom most spot

				if (gGameBoard[rows - i][select - 1] == ' ') {
					gGameBoard[rows - i][select - 1] = p;
					valid = true; // set to true to exit the loop
					break;
				}
				else if (gGameBoard[0][select - 1] == 'x' || gGameBoard[0][select - 1] == 'o') { // player inputs a column that is full, executes once to prevent extra messages
					cout << "\nThe column you selected is full. Please try again.\n\n";
					valid = false;
					break;
				}
			}
		}
	}
	printBoard(); // reprints the board to display where pieces are placed
}

int main()
{
	cout << "Welcome to Connect 4!\n"; // initial message for user, introduces the game

	setBoardSize(); // asks user for board size, creates it, initializes it, then prints the board to the console
	createGameBoard();
	initBoard();
	printBoard();

	while (win < 1) { // while loop for gameplay, constantly lets the players make moves, checks for a win/tie, and prints the game board

		playerGo('x'); // player x takes a turn, then is checked for a win or tie
		checkWin('x');
		checkTie();

		if (win < 1) { // decision that allows player o to go

				playerGo('o'); // player o takes a turn, then is checked for a win or tie
				checkWin('o');
				checkTie();
		}
		else { break; } // exits the loop if win is greater than 0
	}

	cout << "\nGame over!";
	delete[] gGameBoard;
	return 0;
}