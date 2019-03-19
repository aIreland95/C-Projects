// FunctionPractice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int myAdd(int x, int y) {

	return x + y;
}

void myAdd2(int x, int y, int& sum) {

	sum = x + y;
}

int main()
{
	int a = 2, b = 6;
	int c = 7, d = 3;
	int sum, sum2;

	sum = myAdd(a, b);
	myAdd2(c, d, sum2);

	cout << "Sum of " << a << " and " << b << " is: " << sum << "\n";
	cout << "Sum of " << c << " and " << d << " is: " << sum2 << "\n";
    return 0;
}

