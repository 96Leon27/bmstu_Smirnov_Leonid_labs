#include <iostream>
using namespace std;

int main() {
	// ввод переменной числа
	int n = 0;
	cin >> n;

	// вычисление делимости
	bool fl1 = n % 3 == 0;
	bool fl2 = n % 5 == 0;

	// выводим результат в зависимости от флагов
	if (fl1 && fl2) {
		cout << "Число делится и на 3, и на 5" << endl;
	} else if (fl1) {
		cout << "Число делится только на 3" << endl;
	} else if (fl2) {
		cout << "Число делится только на 5" << endl;
	} else {
		cout << "Число не делится ни на 3, ни на 5" << endl;
	}
	return 0;
}
