// ============================================================================
// file: sum.cpp
// ============================================================================
// Programmer: Isaias Soria
// Date: 02/08/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
//
// Description: This program takes three integer inputs and sums them,
//              then prints the sum.
//
// ============================================================================

#include <iostream>
using namespace std;

int main(void)
{
    int a;
    int b;
    int c;
    int sum;

    cout << "Enter integer one: ";
    cin >> a; 
    cout << "Enter integer two: ";
    cin >> b; 
    cout << "Enter integer three: "; 
    cin >> c; 

    sum = a + b + c;
    cout << a << " + " << b << " + " << c << " = " << sum << endl; 

    return 0;

}