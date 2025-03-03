// ===================================================================================================
// file: range.cpp
// ===================================================================================================
// Programmer: Isaias Soria
// Date: 03/2/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
//
// Description: This program calculates the range of even values and any other multiples. 
//      The program will display a range of even numbers from 1-25, then a range of a lower bound 
//      to an upper bound (inputted by the user) of even numbers, and lastly a range of lower to an 
//      upper bound (inputted by the user from before) and a user-provided divisor. This will give you 
//      practice in writing for loops, exit function, and overloading functions.
//
// ===================================================================================================

#include <iostream>
#include <cstdlib>

using namespace std;

// function prototypes
void DispVal(int val);
void Range(void);
void Range(int lower, int upper);
void Range(int lower, int upper, int divisor);


int main(void)
{
    int lower = 0;
    int upper = 0;
    int divisor = 0;
    cout << "\nEnter an integer lower and upper boundaries and divisor of the range separated by white space: ";
    cin >> lower >> upper >> divisor;
    
    //Checking lower is not greater than upper bounds
    if(lower > upper)
    {
        cout << "\nLower number is greater than upper" << endl;
        cout << "Exiting..." << endl;
        exit(1);
    }

    cout << "\nCalling the Range function with no arguments" << endl;
    Range();

    cout << "\nCalling the Range function with upper & lower arguments" << endl;
    Range(lower, upper);

    cout << "\nCalling the Range function with upper, lower, & divisor arguments" << endl;
    Range(lower, upper, divisor);

}

//displays a integer value then adds a space
void DispVal(int val)
{
    cout << val << " ";
}

// Function to display even numbers from 1 to 25
void Range(void)
{
    for (int i = 2; i <= 25; i += 2)
    {
        DispVal(i);
    }
    cout << endl;
}

// Function to display even numbers between the user-provided integers lower and upper bounds
void Range(int lower, int upper) 
{
    //counter for going to newline when there has been 22 numbers printed
    int spaceCounter = 0;
    for (int i = lower; i <= upper; i++) 
    {
        if (i % 2 == 0) 
        { 
            DispVal(i); 
            spaceCounter++;
        }
        if(spaceCounter > 22)
        {
            cout << endl;
            spaceCounter = 0;
        }
    }
    cout << endl;
}

// Function to display numbers divisible by the provided divisor within the user-provided bounds
void Range(int lower, int upper, int divisor) 
{
    //counter for going to newline when there has been 22 numbers printed
    int spaceCounter = 0;
    for (int i = lower; i <= upper; i++) 
    {
        if (i % divisor == 0) 
        {  
            DispVal(i);  
            spaceCounter++;
        }
        if(spaceCounter > 22)
        {
            cout << endl;
            spaceCounter = 0;
        }
    }
    cout << endl;
}

