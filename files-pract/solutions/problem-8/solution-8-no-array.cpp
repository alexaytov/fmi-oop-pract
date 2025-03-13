#include "helper_functions.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	InitializeTestData();

	fstream fileStream("file.bin", ios::in|ios::out|ios::binary);
	if (!fileStream)
	{
		cout << "Couldn't open file!\n";
		cout << fileStream.is_open() << " " << fileStream.bad() << " " << fileStream.fail() << endl;
		return 1;
	}

	fileStream.seekg(0, ios::end);
	int n = fileStream.tellg() / sizeof(int);

	for (int i = 0; i <= n - 2; i++) {

		int k = i;
		fileStream.seekg(k * sizeof(int));
		int min;
		fileStream.read((char*)&min, sizeof(int));

		for (int j = i + 1; j <= n - 1; j++)
		{
			fileStream.seekg(j * sizeof(int));
			int current;
			fileStream.read((char*)&current, sizeof(int));
			if (current < min)
			{
				k = j;
				min = current;
			}
		}

		int temp1, temp2;

		fileStream.seekg(i * sizeof(int));
		fileStream.read((char*)&temp1, sizeof(int));

		fileStream.seekg(k * sizeof(int));
		fileStream.read((char*)&temp2, sizeof(int));

		fileStream.seekp(k * sizeof(int));
		fileStream.write((const char*)&temp1, sizeof(int));

		fileStream.seekp(i * sizeof(int));
		fileStream.write((const char*)&temp2, sizeof(int));
	}

	fileStream.seekg(0, ios::beg);
	int extractedNumber;
	while (fileStream.read((char*)&extractedNumber, sizeof(int)))
	{
		cout << extractedNumber << " ";
	}
	cout << endl;

	fileStream.close();

	return 0;
}