// ===================================================================================================
// file: calc.cpp
// ===================================================================================================
// Programmer: Isaias Soria
// Date: 03/2/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
//
// Description: This program calculates sum, difference, product, and quotient with the remainder of
//              two integers received from input. The output uses variables passed by reference.
//
// ===================================================================================================

#include <iostream>
#include <cctype>

using namespace std;

// function prototypes
void Sum(int a, int b, int& sum);
void Difference(int a, int b, int& diff);
void Product(int a, int b, int& product);
void Division(int a, int b, int& quotient, int& remainder);

int main(void)
{
    //variables
    int a = 0;
    int b = 0;
    int sum = 0;
    int diff = 0;
    int product = 0;
    int quotient = 0;
    int remainder = 0;
    char decision = 'y';

    while(decision == 'y')
    {
        cout << "Please enter two integer values separated by whitespace: ";
        cin >> a >> b;
        cout << "Here are the results:" << endl;

        //calling functions
        Sum(a, b, sum);
        Difference(a, b, diff);
        Product(a, b, product);
        
        cout << a << " + " << b << " = " << sum << endl;
        cout << a << " - " << b << " = " << diff << endl;
        cout << a << " * " << b << " = " << product << endl;

        //checking for zero
        if(a != 0 && b != 0)
        {
            Division(a, b, quotient, remainder);
            cout << a << " / " << b << " = " << quotient << " with a remainder of " << remainder << endl;
        }
        else
        {
            cout << "Division by zero is undefined..." << endl;
        }

        //setting up next calc
        cout << "\nWould you like to try different numbers (Y/N)? ";
        cin >> decision; 
        decision = tolower(decision);
        cout << endl;

    }

    //terminate program
    return 0;

}

void Sum(int a, int b, int& sum)
{
    sum = a + b;
}

void Difference(int a, int b, int& diff)
{
    diff = a - b;
}

void Product(int a, int b, int& product)
{
    product = a * b;
}

void Division(int a, int b, int& quotient, int& remainder)
{
    quotient = a / b;
    remainder = a % b;
}