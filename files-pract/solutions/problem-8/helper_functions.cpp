#include <iostream>
#include <fstream>

using namespace std;

void SelectionSortArray(int a[], int n) {

	// Външният цикъл минава през всеки един от елементите, без последния:
	for (int i = 0; i <= n - 2; i++)
	{
		// Записваме индекса на текущия елемент и итерираме през остатъка от масива,
		// като целта ни е да намерим индекса на най-малкия елемент:
		int k = i;
		for (int j = i + 1; j <= n - 1; j++)
		{
			if (a[j] < a[k]) k = j;
		}
		// След като сме намерили индекса на най-малкия елемент, разменяме елемента с
		// текущия (на позиция i) като така всички елементи с индекси 0...i са сортирани:
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
	// На стъпка i = n - 2, алгоритъмът завършва и всички елементи са сортирани
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

		fileOutputStream.write((const char*) &testData[i], sizeof(int));
	}

	fileOutputStream.close();
}
