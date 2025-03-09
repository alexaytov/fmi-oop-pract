#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    int wordCount = 0;
    
    // possible approach if we need to count words in each line
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            wordCount++;
        }
    }

    file.close();
    std::cout << "Word count: " << wordCount << std::endl;

    return 0;
}