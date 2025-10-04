#include <iostream>
#include <cmath>
using namespace std;


int main() {

	// задание переменных
	const int n = 3;

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

	double Cx = (arr_x[0] + arr_x[1] + arr_x[2]) / 3;
	double Cy = (arr_y[0] + arr_y[1] + arr_y[2]) / 3;

	// вывод результатов
	cout << "Центр масс Cx: " << Cx << endl << "Центр масс Cy: " << Cy << endl;

	return 0;
}
