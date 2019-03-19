// Structures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Student {

	string firstName;
	string lastName;
	int age;
	int gradYear;
};

int main()
{
	const int NUM_STUDENTS = 5;
	Student records[NUM_STUDENTS];

	for (int i = 0; i < NUM_STUDENTS; i++) {

		cout << "Please enter the first name of student " << i + 1 << ": ";
		cin >> records[i].firstName;
		cout << "\nPlease enter the last name of student " << i + 1 << ": ";
		cin >> records[i].lastName;
		cout << "\nPlease enter the age of student " << i + 1 << ": ";
		cin >> records[i].age;
		cout << "\nPlease enter the graduation year of student " << i + 1 << ": ";
		cin >> records[i].gradYear;
		system("CLS");
	}

	system("CLS");
	cout << "Here are all of the student records.\n" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++) {

		cout << "Name: " << records[i].firstName << " " << records[i].lastName << "\nAge: " << records[i].age << "\nGraduation Year: " << records[i].gradYear << "\n" << endl;
	}

	/*Person mike = {30, "Mike", "Jordan", "October 1, 1988"};
	Person jim = { 20, "Jim", "Slim", "May 30, 1998" };

	cout << mike.age << endl;*/

    return 0;
}

