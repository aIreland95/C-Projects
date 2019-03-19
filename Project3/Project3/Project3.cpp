// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <time.h>
using namespace std;

// Aaron Ireland
// September 30, 2018
// Project 3 - Word Guesser

string hint; // string for holding the answer's hint
string word; // string for holding the answer itself
string display; // string that will show underscores
string wrongGuesses; //string that will contain wrong guesses
int correct = 0; // counter for the number of correct guesses/letters

// helper function: selects a random hint: answer pair from answers.txt
int randomWord(int linenum) {

	ifstream file; // stream for using a file for input
	string str;
	int numlineMax = 6;

	file.open("answers.txt"); // opens the answers.txt file

	if (file.is_open()) { // checks if answers.txt is open

		int count = linenum; // count used to determine what line will be used

		while (!file.eof() && count < numlineMax) {

			getline(file, str, ':'); // pulls a line from the file, using the : as a seperator

			string answer;
			file >> answer; // sets the answer to the second part of the line (seperated by :)
			hint = str; // sets the first part of the line as the hint
			word = answer;
			count++;

		}
		file.close();

	}
	else { // else statement incase the file is not able to be opened
		cout << "File is unavailable..." << endl;
		return -1;
	}

}

// helper function: displays underscores to the user
void gameDisplay() {

	display = word; // sets display to be the value of word, or answer in this case

	for (int i = 0; i < display.length(); i++) { // displays each character in display as an undersocre

		display[i] = '_';
	}
}

// helper function: prints out the hint, wrong guess list, and answer to the user
void infoDisplay() {

	cout << "\nHint: " << hint << endl; // displays hint
	cout << "\nWrong Guesses:"; // displays wrong guesses, accumulates wrong letters by displaying the vector

	for (int i = 0; i < wrongGuesses.size(); i++) { // displays each vector element
		cout << " " << wrongGuesses.at(i);
	}

	cout << "\n\nAnswer:"; // answer display

	for (int i = 0; i < display.length(); i++) { // displays the hidden word using underscores seperated by spaces
		cout << " " << display[i];
	}
}

// helper function: checks if the user's guess is correct, incorrect, or has been previously guessed
int checkGuess(char g) {


	bool correctGuess = false; // bool to check if guess is correct
	bool duplicate = false; // checks if a guess has already been guessed earlier
	int letterCount = 0;

	for (int i = 0; i < word.length(); i++) {

		if (toupper(g) == toupper(word[i])) { // condition checks if letters are equal and eliminates case sensitivity

			if (display[i] == word[i]) { // statement to check if user's guess is already in the word

				system("CLS");
				cout << "\n" << g << " has already been guessed. Try again.\n";
				duplicate = true;
				break;
			}
			else { // else statement: the guess is not a duplicate, and is correct

				display[i] = word[i]; // sets the visible answer's letter equal to the selected word, increments correct and count, and sets correctGuess to true
				correct++;
				letterCount++;
				correctGuess = true;
			}
		}
	}
	if (duplicate == true) { // sends loop back to the top, avoiding the incorrect guess message
		return 0;
	}

	if (!correctGuess) { // statement that displays if a guess is wrong, adds guess to the wrongGuesses vector

		system("CLS");
		cout << "\n" << g << " is incorrect!\n";
		wrongGuesses.push_back(g);
	}
	else { // statement executes as long as correctGuess is true

		system("CLS");
		cout << "\nCorrect! You revealed " << letterCount << " of the letter " << g << "!\n"; // message that displays the number of letters revealed after a guess
	}
	return 0;
}

// function that cycles through gameplay, ends when correct guess counter is equal to the length of the hidden word
int playGame(string word) {

	gameDisplay(); // helper function: used for displaying the underscores to the user

	while (correct < word.length()) {
		
		infoDisplay(); // helper function: displays hint, wrong guesses, and answer to the user
		cout << "\n\nPlease guess a letter: "; // prompt user to guess a letter, accepts input

		char guess; // user's guess, accepted as input
		cin >> guess;
		checkGuess(guess); // helper function: passes in user's guess to check if correct

	}
	cout << "\nCongratulations! The answer is " << word << "!\n" << endl; // the word is guessed and completely filled in
	return 0;
}

int main()
{
	srand(time(NULL)); // seeding the random function
	const int numLines = 5;
	int r = rand() % numLines + 1; // random integer, used to select a random line from answers.txt

	randomWord(r);
	cout << "Welcome to the Word Guesser!" << endl; // introduction message
	playGame(word); // function for playing through the game, passing the word and hint as parameters
    return 0;
}