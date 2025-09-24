#include <iostream>
using namespace std;

int main() {
	// ввод переменной числа
	int n = 0;
	cin >> n;

	// выводим результат в зависимости от четности
	if (n % 2 == 0) {
		cout << "Число четное" << endl;
	}
	else {
		cout << "Число нечетное" << endl;
	}
	return 0;
}
