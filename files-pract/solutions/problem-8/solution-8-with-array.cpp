#include "helper_functions.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	// Извикваме помощната функция за инициализиране на тестовите данни:
	InitializeTestData();

	ifstream fileInputStream("file.bin", ios::binary);
	if (!fileInputStream)
	{
		cout << "Error! Could not open file!\n";
		return 1;
	}

	// Чрез цикъл извличаме последователно елементите на файла и ги
	// записваме в масива.
	// Обърнете внимание, че инициализираме променливата numbersSize с -1 и
	// на всяка стъпка я увеличаваме с 1, след което записваме на съответната позиция
	// поредното число.
	// (Припомнете си разликата между ++var и var++)
	// Така си гарантираме, че на стъпка n (0...n) операцията ще е неуспешна (тоест няма
	// да има повече елементи във файла и, тъй като n е една стъпка повече от последното
	// успешно извличане, n ще представлява броя на елементите във файла (0...n-1):
	int numbers[1000];
	int numbersSize = -1;
	while (fileInputStream.read((char*)&numbers[++numbersSize], sizeof(int)));

	// Извикваме помощната функция за сортиране на масива:
	SelectionSortArray(numbers, numbersSize);

	// Накрая извждаме елементите на, вече сортирания, масив на екрана:
	for (int i = 0; i < numbersSize; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	fileInputStream.close();

	return 0;
}
