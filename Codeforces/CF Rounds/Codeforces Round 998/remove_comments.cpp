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

    while (i < code.size()) {
        if (inBlockComment) {
            if (i + 1 < code.size() && code[i] == '*' && code[i + 1] == '/') {
                inBlockComment = false;
                i += 2;  // Skip the "*/"
            } else {
                i++;
            }
        } else if (inLineComment) {
            if (code[i] == '\n') {
                inLineComment = false;
                cleanedCode << code[i];
                i++;
            } else {
                i++;
            }
        } else {
            if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '/') {
                inLineComment = true;
                i += 2; // Skip the "//"
            } else if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '*') {
                inBlockComment = true;
                i += 2; // Skip the "/*"
            } else {
                cleanedCode << code[i];
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

    // Remove comments from the code
    string cleanedCode = removeComments(code);

    // Output the cleaned code
    cout << "Cleaned code without comments:" << endl;
    cout << cleanedCode << endl;

    return 0;
}
//     g++ -o remove_comments remove_comments.cpp
//     ./remove_comments
