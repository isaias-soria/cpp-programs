// ============================================================================
// file: cashRegisterFile.cpp
// ============================================================================
// Programmer: Isaias Soria
// Date: 03/11/2025
// Class: CSCI 123 ("Intro to Programming Using C++")
// Instructor: Dr. Rodriguez
//
// Description: This program is a cash register. It takes input from the file 
//              "items.txt" on the amount of items and their prices. It then 
//              calculates the subtotal, applies tax, and determines the total cost. 
//              The user selects a payment method (cash or credit), and if cash is 
//              chosen, it ensures sufficient payment. Finally, it generates a receipt 
//              saved to "receipt.txt".
//
// ============================================================================
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const double TAX_RATE = 0.0775; // 7% tax

void processTransaction(double total, const vector<double>& items) 
{
    char paymentMethod;
    ofstream receipt("receipt.txt", ios::app); // Append to the existing receipt

    if (!receipt) 
    {
        cerr << "Error: Unable to open receipt.txt for writing.\n";
        exit(1);
    }

    // Ensure correct payment selection
    do 
    {
        cout << "\nCash or credit? Enter 'C' for Cash or 'T' for Credit: ";
        cin >> paymentMethod;
        paymentMethod = toupper(paymentMethod);
        if(paymentMethod != 'C' && paymentMethod != 'T')
        {
            cout << "Please select the correct options!" << endl;
        }
    } while (paymentMethod != 'C' && paymentMethod != 'T');

    receipt << fixed << setprecision(2);
    cout << fixed << setprecision(2);

    if (paymentMethod == 'C') 
    {
        double payment;
        cout << "\nCash: $";
        do 
        {   
            cin >> payment;
            if (payment < total) 
            {
                cout << endl;
                cout << "Please enter the correct amount of cash: $";
            }
        } while (payment < total);

        double change = payment - total;
        cout << "Change: $" << change << endl;
        receipt << "\nCash: $" << payment << "\n";
        receipt << "Change: $" << change << "\n";
    } 
    else 
    {
        cout << "Card Payment: $" << total << "\n";
        receipt << "\nCard Payment: $" << total << "\n";
    }

    receipt.close();
}

int main() 
{
    ifstream inputFile("items.txt");
    if (!inputFile) 
    {
        cerr << "Error: Unable to open items.txt. Make sure the file exists.\n";
        exit(1);;
    }

    vector<double> items;
    double item, subtotal = 0.0;
    
    while (inputFile >> item) 
    {
        items.push_back(item);
        subtotal += item;
    }
    
    inputFile.close();
    
    if (items.empty()) 
    {
        cerr << "Error: Invalid item price found in file.\n";
        exit(1);
    }

    double tax = subtotal * TAX_RATE;
    double total = subtotal + tax;
    cout << fixed << setprecision(2);

    cout << "Items:\n";
    for (size_t i = 0; i < items.size(); i++) 
    {
        cout << "        #" << i + 1 << ": $" << items[i] << "\n";
    }

    cout << "\nSubtotal: $" << subtotal << endl;
    cout << "Tax (7%): $" << tax << endl;
    cout << "Total: $" << total << endl;

    // Write receipt
    ofstream receipt("receipt.txt");
    receipt << fixed << setprecision(2);
    receipt << "###########################################################\n";
    receipt << "                          Receipt\n";
    receipt << "###########################################################\n";
    receipt << "Items:\n";

    //loop for items
    for (size_t i = 0; i < items.size(); i++) 
    {
        receipt << "        #" << i + 1 << ": $" << items[i] << "\n";
    }

    receipt << "\nSubtotal: $" << subtotal << "\n";
    receipt << "Tax (7.75%): $" << tax << "\n";
    receipt << "Total: $" << total << "\n";
    receipt.close();

    processTransaction(total, items);

    return 0;
}
