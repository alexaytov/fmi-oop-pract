#include "helper_functions.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	InitializeTestData();

	ifstream fileInputStream("file.bin", ios::binary);
	if (!fileInputStream)
	{
		cout << "Error! Could not open file!\n";
		return 1;
	}

	int numbers[1000];
	int numbersSize = -1;
	while (fileInputStream.read((char*)&numbers[++numbersSize], sizeof(int)));

	SelectionSortArray(numbers, numbersSize);
	for (int i = 0; i < numbersSize; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	fileInputStream.close();

	return 0;
}