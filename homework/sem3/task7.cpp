#include <iostream>
#include <list>
using namespace std;


int zeroing_out(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	return 0;
}

int main() {

	// задание переменных
	const int n = 15;
	int arr[n] = {};
	int An = 0;

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
	
	// обнуление
	if (min_arr == 0 or max_arr == 0) {
		zeroing_out(arr, ind_min_arr);
	}

	// вывод результатов
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	

		

	return 0;
}
