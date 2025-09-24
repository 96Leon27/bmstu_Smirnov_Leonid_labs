#include <iostream>
using namespace std;

int main() {
	// ввод переменных сторон
	double l = 0, h = 0;
	cin >> l;
	cin >> h;

	// ищем площадь
	double s = l * h;

	// выводим результат
	cout << "Площадь:" << s << endl;

	return 0;
}
