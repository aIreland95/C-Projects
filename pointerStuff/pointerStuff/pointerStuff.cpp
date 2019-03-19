// pointerStuff.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//int *gPTR;
//
//void someFunction() {
//	int x = 5;
//	gPTR = &x;
//}
//
//void doNothing() {
//	return;
//}

// USEFUL INFORMATION FOR PROJECT 2!!!

char** gGameBoard;

void createGameBoard(int rows, int columns) {

	gGameBoard = new char*[rows];

	for (i = 0; i < rows; ++i) {
		
		gGameBoard[i] = new char[columns];
	}
}

int main()
{
	/*int x = 4;
	int* p = nullptr;

	if (x == 5) {
		p = &x;
	}

	if (p != nullptr) {

		cout << *p << endl;
	}
	*/

	/*someFunction();
	doNothing();
	cout << *gPTR << endl;
    return 0;*/

	/*int *a;

	a = new int[5];

	a[0] = 10;
	a[1] = 11;


	delete[] a;*/


	createGameBoard(10, 10);
	return 0;
}