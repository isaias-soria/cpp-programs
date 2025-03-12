#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

void cleanFile(const string &inputFile, const string &outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);
    string line;

    if (!inFile) {
        cerr << "Error: Cannot open " << inputFile << endl;
        return;
    }
    
    while (getline(inFile, line)) {
        size_t commentPos = line.find("//");
        if (commentPos != string::npos) {
            line = line.substr(0, commentPos);
        }
        
        string cleanedLine;
        bool lastWasSpace = false;
        for (size_t i = 0; i < line.length(); i++) {
            if (isspace(line[i])) {
                if (!lastWasSpace) {
                    cleanedLine += ' ';
                    lastWasSpace = true;
                }
            } else {
                if (line.substr(i, 5) == "cin>>") {
                    cleanedLine += "cin>>";
                    i += 4;
                    lastWasSpace = false;
                    continue;
                }
                if ((ispunct(line[i]) && line[i] != '_') && (cleanedLine.empty() || cleanedLine.back() != ' ')) {
                    cleanedLine += ' ';
                }
                cleanedLine += line[i];
                lastWasSpace = false;
                if (ispunct(line[i]) && i + 1 < line.length() && line[i + 1] != ' ' && line[i + 1] != '>') {
                    cleanedLine += ' ';
                }
            }
        }
        
        if (!cleanedLine.empty()) {
            outFile << cleanedLine << endl;
        }
    }
    
    inFile.close();
    outFile.close();
}

int main() {
    cleanFile("file.txt", "clean.txt");
    cout << "File cleaned and saved as clean.txt" << endl;
    return 0;
}
