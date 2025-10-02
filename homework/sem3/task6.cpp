#include <iostream>
#include <list>
using namespace std;


int div_2(double arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] /= 2;
	}
	return 0;
}

int main() {

	// задание переменных
	const int n = 15;
	double arr[n] = {};
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
	

	// деление
	if (ind_min_arr == 1 && ind_max_arr == 0) {
		div_2(arr, n);
	}

	// вывод результатов
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	

		

	return 0;
}
