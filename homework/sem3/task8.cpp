#include <iostream>
#include <list>
using namespace std;


int change_arr(int arr[], int ind_min_arr, int n, int max_arr) {
	for (int i = ind_min_arr + 1; i < n; i++) {
		arr[i] = max_arr;
	}
	return 0;
}

int main() {

	// задание переменных
	const int n = 10;
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
	
	// изменяем список
	if (ind_min_arr == 4 and ind_max_arr == 1) {
		change_arr(arr, ind_min_arr, n, max_arr);
	}

	// вывод результатов
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
