// ============================================================================
// file: alphabet.cpp
// ============================================================================
// Programmer: Isaias Soria
// Date: 02/08/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
//
// Description: This program prints the alphabet in upper case using a displayUpperCaseABC function.`
//
// ============================================================================

#include <iostream>
using namespace std;

void displayUpperCaseABC(void)
{
    cout << "A B C D E F G H I J K L M" << endl;
    cout << "N O P Q R S T U V W X Y Z" << endl;
}

int main(void)
{
    cout << "About to call the DisplayUpperCaseABC function...\n" << endl;

    displayUpperCaseABC();

    cout << "\nReturned from the DisplayUpperCaseABC function." << endl;

    return 0;
}
