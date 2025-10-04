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

	int arr_x[n] = {};
	int arr_y[n] = {};

	int x = 0;
	int y = 0;
	
	
	// цикл перебора вершин
	for (int i = 0; i < n; i++) {
		cout << "Введите координаты Х вершины " << i + 1 << ": ";
		cin >> arr_x[i];

		cout << "Введите координаты Y вершины " << i + 1 << ": ";
		cin >> arr_y[i];
	}

	double S = abs(arr_x[0] * (arr_y[1] - arr_y[2]) + arr_x[1] * (arr_y[2] - arr_y[0]) + arr_x[2] * (arr_y[0] - arr_y[1])) / 2.0;

	// вывод результатов
	cout << "Площадь треугольника: " << S << endl;

	return 0;
}
