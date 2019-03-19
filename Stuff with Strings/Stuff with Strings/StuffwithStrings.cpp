// StuffwithStrings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream file;
	string str;

	file.open("sample.txt");

	if (!file.is_open()) {

		cout << "Oops, file not found...";
		return -1;
	}

	while (!file.eof()) {

		getline(file, str);
		cout << str << endl;
	}
}
	

