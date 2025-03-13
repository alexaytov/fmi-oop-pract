#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream fileInputStream("data.txt");
	if (!fileInputStream) 
	{
		cout << "Error! Cannot open file!\n";
		return 1;
	}

	fileInputStream.seekg(0, ios::end);
	cout << "Number of characters in the file: " << fileInputStream.tellg() << endl;

	cout << "Enter symbol index: ";
	int index;
	cin >> index;

	fileInputStream.seekg(index, ios::beg);
	char symbol;
	fileInputStream.get(symbol);
	cout << "Symbol at index " << index << ": " << symbol << endl;

	fileInputStream.close();

	return 0;
}
