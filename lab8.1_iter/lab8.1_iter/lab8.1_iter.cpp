// lab8.1_iter.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 8.1
// Опрацювання багатовимірних масивів ітераційними та рекурсивними способами
// Варіант 19

// abccabbcanbmcnacnb

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, const char* strC, int* indexArr);
char* Change(char* str, int* indexArr);

int main() {
	char str[101];
	int  count = 0;
	int* arr = new int[34];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	count = Count(str, "abc", arr);
	cout << "String contained " << count << " groups of 'a', 'b', 'c'" << endl;

	cout << "Modified string (param) : " << str << endl;
	char* dest = new char[101];
	dest = Change(str, arr);
	cout << "Modified string (result): " << dest << endl;

	return 0;
}

int Count(char* str, const char* strC, int* indexArr) {
	if (strlen(str) < 3)
		return 0;

	int k = 0;
	bool b = 0;
	int counter = 0;
	for (int i = 0; str[i] != 0; i++) {
		b = false;
		for (int j = 0; j <= 2; j++) {
			if (str[i] == strC[j]) {
				b = true;
				counter++;
			}
		}
		if (counter != 0) {
			if (!b) {
				counter -= counter % 3;
			}
			else if (counter % 3 == 0) {
				indexArr[k] = i - 2;
				k++;
			}
		}
	}

	return counter / 3;
}

char* Change(char* str, int* indexArr) {
	size_t len = strlen(str);
	if (len < 3)
		return str;

	int k = 0;
	size_t i = 0;
	char* tmp = new char[len * 2/3 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	while (i < len && str[i] != 0) {
		if (i == indexArr[k]) {
			strcat(t, "**");
			t += 2;
			i += 2;
			k++;
		}
		else {
			*t++ = str[i];
			*t = '\0';
		}
		i++;
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}