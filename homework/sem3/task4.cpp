#include <iostream>
using namespace std;

int main() {

	// задание переменных
	int n = 15;
	double arr[15] = {};
	double An = 0;

	int min_arr = 0;
	int ind_min_arr = 0;
	int max_arr = 0;
	int ind_max_arr = 0;
	
	// цикл перебора элементов последовательности
	for (int i = 0; i < n; i++) {
		cin >> An;
		arr[i] = An;
		if (i == 0) {

			min_arr = An;
			max_arr = An;
		}
		else {
			if (An > max_arr) {
				max_arr = An;
				ind_max_arr = i;
			}
			else if (An < min_arr) {
				min_arr = An;
				ind_min_arr = i;
			}
		}
	}
	

	// вывод результатов
	if (ind_max_arr < ind_min_arr) {
		cout << max_arr << " * " << min_arr << " = " << max_arr * min_arr << endl;
	}
	else {
		cout << "Максимальный элемент последовательности идет после минимального элемента последовательности" << endl;
	}
		

	return 0;
}
