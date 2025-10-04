#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


// функция высчета дистанции между парой точек
double d(double x1, double y1, double x2, double y2) {
	return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
}

int main() {

	// задание переменных
	const int n = 4;

	double arr_x[n] = {};
	double arr_y[n] = {};

	double x = 0;
	double y = 0;
	
	
	// цикл перебора вершин
	for (int i = 0; i < n; i++) {
		cout << "Введите координаты Х вершины " << i + 1 << ": ";
		cin >> arr_x[i];

		cout << "Введите координаты Y вершины " << i + 1 << ": ";
		cin >> arr_y[i];
	}

	double d1 = 0.0;
	double l = 0.0;
	for (int i = 0; i < n; i++) {
		l = d(arr_x[0], arr_y[0], arr_x[i], arr_y[i]);
		if (l > d1) {
			d1 = l;
		}
	}
	



	// вывод результатов
	cout << "Диагональ: " << d1 << endl;

	return 0;
}
