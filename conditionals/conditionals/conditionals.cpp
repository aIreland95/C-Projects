// conditionals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int x = 3;

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < 2; j++) {

			cout << "Hello ";
		}
		cout << endl;
	}

	cout << "Goodbye!" << endl;
}

