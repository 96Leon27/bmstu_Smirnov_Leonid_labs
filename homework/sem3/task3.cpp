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

	// меняем местами
	if (ind_max_arr == 0 && ind_min_arr == n - 1) {
		arr[0] = min_arr;
		arr[n - 1] = max_arr;
	}
	else if (ind_max_arr == 0) {
		arr[0] = arr[n - 1];
		arr[n - 1] = max_arr;
		arr[ind_min_arr] = arr[0];
		arr[0] = min_arr;
	}
	else if (ind_min_arr = n - 1) {
		arr[n - 1] = arr[0];
		arr[0] = min_arr;
		arr[ind_max_arr] = arr[n - 1];
		arr[n - 1] = max_arr;
	}
	else {

		arr[ind_min_arr] = arr[0];
		arr[0] = arr[min_arr];
		
		arr[ind_max_arr] = arr[n - 1];
		arr[n - 1] = max_arr;
		
	}
	

	// вывод результатов
	cout << "------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " элемент последовательности: " << arr[i] << endl;
	}
	return 0;
}
