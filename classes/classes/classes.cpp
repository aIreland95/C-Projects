// classes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Person {

public:

	// this is a constructor
	Person(string _name) {

		name = _name;
		count++;

		if (count == 1) {

			cout << count << " person is here." << endl;
		}
		else {

			cout << count << " people are here." << endl;
		}	
	}

	string getName() {
		return name;
	}

private:

	string name;
	string birthday;

	static int count;
	static const int number = 5; // static const variables can be initialized in a class
};

int Person::count = 0;

int main()
{
	Person person1("Mike");
	Person* person2 = new Person("Alfonzo");

	cout << person1.getName() << endl;
	cout << person2->getName() << endl;

    return 0;
}

