#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int numbers[] = {1, 2, 3, 4, 5};

    ofstream writeFile("output.bin", ios::binary);
    if (!writeFile) {
        cout << "Couldn't open file for writing!" << endl;
        return 1;
    }

    writeFile.write((char*)numbers, sizeof(numbers));
    writeFile.close();

    ifstream readFile("output.bin", ios::binary);
    if (!readFile) {
        cout << "File not found!" << endl;
        return 1;
    }

    int numbers2[5];
    readFile.read((char*)numbers2, sizeof(numbers2));
    readFile.close();

    for (int i = 0; i < 5; i++) {
        cout << numbers2[i] << endl;
    }
}