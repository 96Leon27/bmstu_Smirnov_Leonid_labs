#include <iostream>
using namespace std;

int main() {
	// ввод переменной цикла
	int n = 0;
	cin >> n;

	// проверка на корректность
	if (n < 0) {
		cout << "Ввод некорректен" << endl;
		return 0;
	}
	
	// вывод квадратов
	for (int i = 1; i <= n; i++) {
		cout << "Квадрат числа " << i << " = " << i * i << endl;
	}

	return 0;
}
