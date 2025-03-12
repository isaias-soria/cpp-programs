#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

bool isReservedWord(const string &lexeme) {
    vector<string> reservedWords = {"cin>>", "for", "int", "while"};
    for (const string &word : reservedWords) {
        if (lexeme == word) {
            return true;
        }
    }
    return false;
}

bool isOperator(const string &lexeme) {
    vector<string> operators = {"+", "-", "*", "/", "++", "--"};
    for (const string &op : operators) {
        if (lexeme == op) {
            return true;
        }
    }
    return false;
}

bool isSpecialSymbol(const string &lexeme) {
    vector<string> specialSymbols = {">", "=", ";", "(", ")", ">=", ","};
    for (const string &symbol : specialSymbols) {
        if (lexeme == symbol) {
            return true;
        }
    }
    return false;
}

bool isNumber(const string &lexeme) {
    if (lexeme.empty()) return false;
    for (char ch : lexeme) {
        if (!isdigit(ch) && ch != '-' && ch != '+') {
            return false;
        }
    }
    return true;
}

bool isIdentifier(const string &lexeme) {
    if (lexeme.empty()) return false;
    if (!isalpha(lexeme[0]) && lexeme[0] != '_') {
        return false;
    }
    for (char ch : lexeme) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;
}

int main() {
    string statement;
    char continueInput = 'y';

    while (continueInput == 'y' || continueInput == 'Y') {
        cout << "Enter a statement: ";
        getline(cin, statement);

        // Convert to lowercase for case-insensitive comparison
        for (char &ch : statement) {
            ch = tolower(ch);
        }

        stringstream ss(statement);
        string lexeme;

        while (ss >> lexeme) {
            if (isReservedWord(lexeme)) {
                cout << lexeme << " -> reserved word" << endl;
            } else if (isOperator(lexeme)) {
                cout << lexeme << " -> operator" << endl;
            } else if (isSpecialSymbol(lexeme)) {
                cout << lexeme << " -> special symbol" << endl;
            } else if (isNumber(lexeme)) {
                cout << lexeme << " -> number" << endl;
            } else if (isIdentifier(lexeme)) {
                cout << lexeme << " -> identifier" << endl;
            } else {
                cout << lexeme << " -> invalid" << endl;
            }
        }

        cout << "CONTINUE(y/n)? ";
        cin >> continueInput;
        cin.ignore(); // To clear the newline character after the input
    }

    return 0;
}
