#include "helper_functions.h"

#include <iostream>
#include <fstream>

using namespace std;

int main() {

	// Извикваме помощната функция за инициализиране на тестовите данни:
	InitializeTestData();

	// Отваряме файловия поток за писане и четене с подходящи флагове,
	// след което проверяваме дали успешно е бил отворен:
	fstream fileStream("file.bin", ios::in|ios::out|ios::binary);
	if (!fileStream)
	{
		cout << "Couldn't open file!\n";
		return 1;
	}

	// Поставяме указателя за четене от файла в края на файла.
	// Тъй като указателят сочи точно след последния символ,
	// функцията tellg() връща броя на байтовете във файла.
	// Разделяйки общия брой на байтовете във файла на броя на байтовете,
	// които заема променлива от тип 'int' получаваме общия брой на числата
	// записани във файла:
	fileStream.seekg(0, ios::end);
	int n = fileStream.tellg() / sizeof(int);

	for (int i = 0; i <= n - 2; i++) {

		// Поставяме указателя за четене от файла на позиция k.
		// След това прочитаме числото записано на тази позиция и го
		// запомняме в променливата 'min':
		int k = i;
		fileStream.seekg(k * sizeof(int));
		int min;
		fileStream.read((char*)&min, sizeof(int));

		for (int j = i + 1; j <= n - 1; j++)
		{
			// Аналогично на горното обяснение, поставяме указателя за
			// четене на позиция j, на която се намира текущия елемент на файла.
			// Правим сравнение с числото в променливата 'min' и ако то се окаже
			// по-голяма от текущо извлеченото, записваме в 'min' новата най-малка
			// стойност (открита до този момент), като запомняме в променливата 'k'
			// и позицията на новата стойност във файла:
			fileStream.seekg(j * sizeof(int));
			int current;
			fileStream.read((char*)&current, sizeof(int));
			if (current < min)
			{
				k = j;
				min = current;
			}
		}

		// Помощни променливи за размяна на стойностите във файла:
		int temp1, temp2;

		// Преместваме позицията за четене от файла да сочи числото
		// на позиция i.
		// След това извличаме байтовете на числото и записваме стойността му
		// в променливата 'temp1':
		fileStream.seekg(i * sizeof(int));
		fileStream.read((char*)&temp1, sizeof(int));

		// Аналогично записваме стойността на числото на позиция k
		// в променливата 'temp2':
		fileStream.seekg(k * sizeof(int));
		fileStream.read((char*)&temp2, sizeof(int));

		// Преместваме позицията за писане във файла да сочи числото
		// на позиция k.
		// Там записваме стойността на променливата temp1
		// (която съдържа старата стойност на позиция i):
		fileStream.seekp(k * sizeof(int));
		fileStream.write((const char*)&temp1, sizeof(int));

		// Аналогично записваме на позиция i стойността на променливата temp2
		// (която съдържа старата стойност на позиция k):
		fileStream.seekp(i * sizeof(int));
		fileStream.write((const char*)&temp2, sizeof(int));

		// В края на цикъла, това, коет направихме е след като сме намерили
		// позицията на числото с най-малка стойност (позиция k),
		// разменяме въпросното число с числото на текущата позиция от външния цикъл
		// (позиция i)
	}

	// За тестване, накрая, извеждаме последователно числата
	// във файла, които вече са сортирани във възходящ ред:
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
