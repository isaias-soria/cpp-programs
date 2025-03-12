#include <iostream>
#include <string>

using namespace std;

// DFA Transition Table
// States: 0 = start, 1 = 'a' seen, 2 = 'a' followed by (a or b*), 3 = 'a(a|b*)a', 4 = Accepting state
int transitionTable[4][2] = {
    {1, -1},  // State 0: 'a' -> 1, 'b' -> invalid
    {2, 1},   // State 1: 'a' -> 2, 'b' -> 1
    {3, 3},   // State 2: 'a' -> 3, 'b' -> 3
    {-1, 3},  // State 3: 'a' -> invalid, 'b' -> 3
};

bool isAccepted(string input) {
    int state = 0;
    for (char c : input) {
        if (c == '$') break;
        int symbol = (c == 'a') ? 0 : (c == 'b') ? 1 : -1;
        if (symbol == -1 || state == -1) return false;
        state = transitionTable[state][symbol];
    }
    return (state == 2 || state == 3);
}

int main() {
    string input;
    cout << "Enter a string ending with '$': ";
    cin >> input;
    cout << (isAccepted(input) ? "YES" : "NO") << endl;
    return 0;
}
