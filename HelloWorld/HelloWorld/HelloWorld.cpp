// HelloWorld.cpp : Defines the entry point for the console application.
// In-Class Workspace Place

#include "stdafx.h"
#include <iostream>
using namespace std;

int addNumbers(int& x, int& y)
{
	x++;
	return x + y;
}

int main()
{
	int num1 = 4;
	int num2 = 6;

	int sum = addNumbers(num1, num2);
	cout << num1 << endl;
	cout << num2 << endl;
	cout << sum << endl;
}