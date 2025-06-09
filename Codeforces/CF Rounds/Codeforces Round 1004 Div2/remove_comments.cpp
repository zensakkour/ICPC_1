#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string removeComments(const string& code) {
    stringstream cleanedCode;
    bool inBlockComment = false;
    bool inLineComment = false;
    size_t i = 0;
    bool newLineNeeded = false; // Track whether we need a new line

    while (i < code.size()) {
        if (inBlockComment) {
            if (i + 1 < code.size() && code[i] == '*' && code[i + 1] == '/') {
                inBlockComment = false;
                i += 2; // Skip "*/"
            } else {
                i++;
            }
        } else if (inLineComment) {
            if (code[i] == '\n') {
                inLineComment = false;
                cleanedCode << '\n'; // Preserve new line structure
                i++;
            } else {
                i++;
            }
        } else {
            if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '/') {
                inLineComment = true;
                while (i < code.size() && code[i] != '\n') i++; // Skip to end of line
            } else if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '*') {
                inBlockComment = true;
                i += 2; // Skip "/*"
            } else {
                if (code[i] != '\n' || !newLineNeeded) {
                    cleanedCode << code[i]; // Only add non-empty lines
                }
                newLineNeeded = (code[i] == '\n'); // Track new lines
                i++;
            }
        }
    }
    
    return cleanedCode.str();
}

int main() {
    // Read the file path
    string filename;
    cout << "Enter the path of the C++ file to remove comments from: ";
    getline(cin, filename);

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string code = buffer.str();
    inputFile.close();

    // Remove comments from the code
    string cleanedCode = removeComments(code);

    // Overwrite the original file with the cleaned code
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error writing to file!" << endl;
        return 1;
    }
    
    outputFile << cleanedCode;
    outputFile.close();

    cout << "Comments removed successfully from " << filename << endl";

    return 0;
}
