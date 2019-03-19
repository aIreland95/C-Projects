// Objects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Person {

	string name;
	int age;
};

int main()
{
	Person dude;

	dude.name = "Mike";
	dude.age = 30;

	Person dudette;

	dudette.name = "Cindy";
	dudette.age = 28;

	Person* p;
	p = &dude; // here, p points to dude

	Person* p2 = &dude;

	cout << dude.name << endl;
	cout << p->name << endl;
	cout << p2->name << endl;

	cout << "\nGuess what day it is? ";

    return 0;
}

