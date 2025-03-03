// ============================================================================
// file: piCalc.cpp
// ============================================================================
// Programmer: Isaias Soria
// Date:
// Class: CSCI 123 ("Intro to Programming Using C++")
// Time:
// Instructor: Dr. Rodriguez
// Project: Pi Calculation
//
// Description:
//      This program calculate the value of pi through iteration or
// approximation.
//
// ============================================================================

#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

// Function Prototypes
void	Iterate(int iter);
void	DecimalApprox(int approx);
void	DisplayPi(int signif, double pi);

// ==== main ==================================================================
//
// ============================================================================

int	main()
{
	char choice; // variables
	int iterations = 0;
	int approx = 0;

	// Prompt the user if they want to iterate or have a decimal approx.
	cout << "\nThis program calculates the number Pi.\n\n";

	// Create a do while loop to prompt the user for Iteration or Approx.
	// Loop until the user enters the correct selection
	do {
        cout << "Would you like to calculate it through I>teration or A>pproximation? ";
        cin >> choice;
        choice = tolower(choice); // Convert to lowercase

        if (choice != 'i' && choice != 'a') 
		{
            cout << "Incorrect Selection. Try again..." << endl;
        }

    } while (choice != 'i' && choice != 'a'); 

	// If it is iteration, ask how many iterations and call the
	// Iterate function.
	if (choice == 'i')
	{
		// Prompt the user of how many iterations
		cout << "How many iterations?: ";
		cin >> iterations;

		// Call the Iterate function
		Iterate(iterations);
	}

	// If it is approximation, ask the number of approximation and call
	// the DecimalApprox function
	else 
	{
		// Prompt the user of decimal approximation
		cout << "How many decimals of approximation?: ";
		cin >> approx;

		// Call the DecimalApprox function
		DecimalApprox(approx);
	}
	return 0;
}   // end of "main"



// ==== Iterate ===============================================================
//
// This function calcuates pi through iteration
//
// Input:
// iter [IN] -- an integer value containing the number of iterations
//
// Output:
// The value of pi.
//
// ============================================================================

void	Iterate(int iter)
{
	double piVal = 0.0; // variables

	// do a loop to calculate pi based on the number of iterations
	for (int i = 0; i < iter; i++)
	{
		piVal += pow(-1, i) / (2 * i + 1);
	}

	piVal *= 4;
	// Call the DisplayPi function.
	// default to 5 digit significance for iteration
	DisplayPi(5, piVal);

} // end of "Iterate"



// ==== DecimalApprox ==========================================================
//
// This function calcuates pi through decimal approximation
//
// Input:
// approx [IN] -- an integer value containing the approximation
//
// Output:
// The value of pi.
//
// ============================================================================

void	DecimalApprox(int approx)
{
	int i = 0; // variables
	double	piVal = 0.0;// Pi value
	double	previousPi = 0.0;	// Previous pi value

	// loop to calculate pi based on the approx value of signif. digits.
	do{
		piVal += (pow(-1, i) / (2 * i + 1)); // calculate PI
		
		// check if the significance has changed within 1 decimial approx.
		// if so break out of the loop
		if (abs(piVal - previousPi) <= pow(10.0, -1.0 * approx))
		{
			break;
		}

		previousPi = piVal;
		i++;

	} while (true);

	piVal *= 4;

	// Call the DisplayPi function.
	// default to approx digit significance for iteration
	DisplayPi(approx, piVal);

} // end of "DecimalApprox"



// ==== DisplayPi =============================================================
//
// This function displays the value of pi.
//
// Input:
// signif [IN] -- an integer value containing the number of digit significance
// pi	  [IN] -- a double value containing the value of pi.
//
// Output:
// void
//
// ============================================================================

void	DisplayPi(int signif, double pi)
{
	// settings for digit precision
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(signif);

	// display the value of pi
	cout << "The value of Pi is: " << pi << endl << endl;
} // end of "DisplayPi"
