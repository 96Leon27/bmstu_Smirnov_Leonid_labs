#include <iostream>
#include <cmath>
using namespace std;


// функция высчета дистанции между парой точек
int d(int x1, int y1, int x2, int y2) {
	return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
}

int main() {

	// задание переменных
	const int n = 3;

	int f_x = 0;
	int f_y = 0;
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;

	int P = 0;

	cout << "Введите координаты Х вершины 1: ";
	cin >> x1;
	f_x = x1;

	cout << "Введите координаты Y вершины 1: ";
	cin >> y1;
	f_y = y1;
	
	
	// цикл перебора вершин
	for (int i = 1; i <= n; i++) {
		cout << "Введите координаты Х вершины " << i + 1 << ": ";
		cin >> x2;

		cout << "Введите координаты Y вершины " << i + 1 << ": ";
		cin >> y2;

		P += d(x1, y1, x2, y2);
		x1 = x2;
		y1 = y2;
	}

	P += d(x1, y1, f_x, f_y);

	// вывод результатов
	cout << "Перимитер многоугольника: " << P << endl;

	return 0;
}
