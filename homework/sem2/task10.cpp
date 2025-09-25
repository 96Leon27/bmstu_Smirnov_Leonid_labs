#include <iostream>
using namespace std;

int main() {
	// ввод переменной
	int n = 0;
	cin >> n;

	// выводим результат в зависимости от ввода
	if (n == 0) {
		cout << "Число равно 0 " << endl;
	}
	else if (n < 0) {
		cout << "Число меньше 0" << endl;
	}
	else {
		cout << "Число больше 0" << endl;
	}
	

	return 0;
}
