// PointersIntro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int A[3] = { 0, 1, 2 };

	cout << A << endl;
	cout << &A[0] << endl;

	cout << *A << endl;
	cout << *(A + 1) << endl;
	cout << *(A + 2) << endl;
    return 0;
}

