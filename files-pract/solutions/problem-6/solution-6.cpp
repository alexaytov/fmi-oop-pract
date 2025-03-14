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

	// Поставяме указателя за извличане на потоко в края на файла:
	fileInputStream.seekg(0, ios::end);
	// Тъй като указателя е поставен в края на файла и няма повече символи,
	// функцията tellg() връща броя на символите във файла:
	cout << "Number of characters in the file: " << fileInputStream.tellg() << endl;

	// Извличаме индекс на символ на файла от конзолата:
	// ЗАБЕЛЕЖКА! (Файловете, също като масивите започват индексирането си от 0-вата позиция)
	cout << "Enter symbol index: ";
	int index;
	cin >> index;

	// Преместваме указателя за извличане на съответната позиция,
	// след което извличаме символа на позицията и го отпечатваме на конзолата:
	fileInputStream.seekg(index, ios::beg);
	char symbol;
	fileInputStream.get(symbol);
	cout << "Symbol at index " << index << ": " << symbol << endl;

	fileInputStream.close();

	return 0;
}
