#include <iostream>
using namespace std;

int main() {
	// ввод переменной сантиметров
	int sm = 0;
	cin >> sm;

	// отделяем метры
	int m = sm / 100;
	sm -= 100 * m;

	// выводим результат
	cout << "Метры:" << m << endl;
	cout << "Сантиметры:" << sm << endl;

	return 0;
}
