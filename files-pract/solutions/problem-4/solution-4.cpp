#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fileToCopy("output.txt");
    if (!fileToCopy) {
        cout << "File not found!" << endl;
        return 1;
    }

    // copy data to another file
    ofstream copyStream("output2.txt");
    if (!copyStream) {
        cout << "Couldn't open file for writing!" << endl;
        return 1;
    }

    string line;
    while (getline(fileToCopy, line)) {
        copyStream << line << endl;
    }

    fileToCopy.close();
    copyStream.close();
}