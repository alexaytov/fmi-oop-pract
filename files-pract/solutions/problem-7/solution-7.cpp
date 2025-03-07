#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	// �������� ����� � ����������� ���� ���������� � ���� �������:
	ofstream fileOut("file.txt");
	if (!fileOut)
	{
		cout << "Couldn't open file for writing!\n";
		return 1;
	}

	// ��������� ����������� ����� �� ����������� ����� (�� �� ������ �� ��-�����):
	streambuf* coutOriginalBuffer = cout.rdbuf();

	// ��������� ������ �� ������ fileOut � �� ��������� � ������ �� ���������� �����:
	streambuf* fileOutBuffer = fileOut.rdbuf();
	cout.rdbuf(fileOutBuffer);

	// ���� ����������, ������� �� ������� ����������� �� ����������� �����, � �� �������
	// ��� �����:
	cout << "Test";
	cout << "\n";
	cout << "Another test";

	// �������������� ������ �� ������ �� ����������� ����� � ��������� ������ �� �����:
	cout.rdbuf(coutOriginalBuffer);
	fileOut.close();

	// �������� ����� ������ ���� ��� � ����� �� ������ �� ����:
	ifstream fileIn("file.txt");
	if (!fileIn)
	{
		cout << "File not found!\n";
		return 1;
	}

	// ��������� ������ �� ������ fileIn � �� ��������� � ������ �� ���������� ����:
	streambuf* fileInBuffer = fileIn.rdbuf();
	cin.rdbuf(fileInBuffer);

	// ���� ���������� �� ������ � ������ �� �����, 
	// ����������� ���� ���� ��� �� ��� �� �����,
	// � ����������� ����������� ����� ��������� ����� ��� �� ������
	// (����� �� ���� �� ����� �� ������� ����������� �� �����, ������������,
	// ����� �� �� ����������):
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
	}

	fileIn.close();

	return 0;
}