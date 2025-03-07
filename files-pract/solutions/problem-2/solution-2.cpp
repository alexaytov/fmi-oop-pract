#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // write data into file
    ofstream file("output.txt");

    // check if file is open
    if (!file) {
        cout << "Couldn't open file for writing!" << endl;
        return 1;
    }

    file << "Hello, World!";
    file << "\n";
    file << "This is a test.";
    file.close();

    // read data from file
    ifstream file2("output.txt");

    // check if file exists
    if (!file2) {
        cout << "File not found!" << endl;
        return 1;
    }

    string line;
    while (getline(file2, line)) {
        cout << line << endl;
    }
    file2.close();
}