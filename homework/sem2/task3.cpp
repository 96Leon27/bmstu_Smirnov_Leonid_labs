#include <iostream>
using namespace std;

int main() {
	// ввод переменной градусов Цельсия
	double С = 0;
	cin >> С;

	// высчитываем Фаренгейты
	double f = С * 9 / 5 + 32;

	// выводим результат
	cout << "Температура в Фаренгейтах:" << f << endl;

	return 0;
}
