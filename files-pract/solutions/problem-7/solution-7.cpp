#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	// Отваряме файла и проверяваме дали отварянето е било успешно:
	ofstream fileOut("file.txt");
	if (!fileOut)
	{
		cout << "Couldn't open file for writing!\n";
		return 1;
	}

	// Запазваме оригиналния буфер на стандартния изход (ще ни трябва за по-късно):
	streambuf* coutOriginalBuffer = cout.rdbuf();

	// Извличаме буфера на потока fileOut и го свързваме с потока за стандартен изход:
	streambuf* fileOutBuffer = fileOut.rdbuf();
	cout.rdbuf(fileOutBuffer);

	// Вече пренасочен, потокът не извежда съобщенията на стандартния изход, а ги записва
	// във файла:
	cout << "Test";
	cout << "\n";
	cout << "Another test";

	// Възстановяваме буфера на потока за стандартния изход и затваряме потока на файла:
	cout.rdbuf(coutOriginalBuffer);
	fileOut.close();

	// Отваряме файла отново този път с поток за четене от него:
	ifstream fileIn("file.txt");
	if (!fileIn)
	{
		cout << "File not found!\n";
		return 1;
	}

	// Извличаме буфера на потока fileIn и го свързваме с потока за стандартен вход:
	streambuf* fileInBuffer = fileIn.rdbuf();
	cin.rdbuf(fileInBuffer);

	// Вече пренасочен да работи с буфера на файла, 
	// стандартния вход чете ред по ред от файла,
	// а използвайки стандартния изход извеждаме всеки ред на екрана
	// (имено за това бе нужно да запазим оригиналния му буфер, първоначално,
	// преди да го пренасочим):
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
	}

	fileIn.close();

	return 0;
}