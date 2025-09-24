#include <iostream>
using namespace std;

int main() {
	// ввод переменной сантиметров
	double l = 0, h = 0;
	cin >> l;
	cin >> h;

	// отделяем метры
	double s = l * h;

	// выводим результат
	cout << "Площадь:" << s << endl;

	return 0;
}
