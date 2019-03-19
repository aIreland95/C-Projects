// moreObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct Person {

	string name;
	Person* spouse;
	Person* children;

} OtherPerson;

void printPerson(Person* p) {

	cout << p->name << " is married to " << p->spouse->name << ".";
}

void newChild(Person* p, string name) {

	Person* child = new Person;
	child->name = name;
	child->spouse = NULL;
	child->children = NULL;

	p->children = child;

}

int main()
{
	Person mike;
	Person jen;

	mike.name = "Mike";
	jen.name = "Jen";

	mike.children = NULL;
	jen.children = NULL;

	mike.spouse = &jen;
	jen.spouse = &mike;

	printPerson(&mike);

    return 0;
}

