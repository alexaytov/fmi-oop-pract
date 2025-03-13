#include <iostream>
#include <fstream>

using namespace std;

const int INT_SIZE = sizeof(int);

void SelectionSortArray(int a[], int n) {

	// �������� ����� ������ ���� ����� ���� �� ����������, ��� ���������:
	for (int i = 0; i <= n - 2; i++)
	{
		// ��������� ������� �� ������� ������� � ��������� ���� �������� �� ������,
		// ���� ����� �� � �� ������� ������� �� ���-������ �������:
		int k = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[j] < a[k]) k = j;
		}
		// ���� ���� ��� �������� ������� �� ���-������ �������, ��������� �������� �
		// ������� (�� ������� i) ���� ���� ������ �������� � ������� 0...i �� ���������:
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
	// �� ������ i = n - 2, ����������� �������� � ������ �������� �� ���������
}

void InitializeTestData() {

	ofstream fileOutputStream("file.bin", ios::binary);
	if (!fileOutputStream)
	{
		cout << "Error! Could not open file!\n";
		exit(1);
	}

	int testData[] = { 363565, 2346, 364, 37, 74, 246, 347, 2, 63, 42, 6 };
	const int TEST_DATA_SIZE = 11;

	for (int i = 0; i < TEST_DATA_SIZE; i++) {

		fileOutputStream.write((const char*) &testData[i], INT_SIZE);
	}

	fileOutputStream.close();
}