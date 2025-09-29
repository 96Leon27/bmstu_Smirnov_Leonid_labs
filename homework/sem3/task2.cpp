#include <iostream>
using namespace std;

int main() {

	// задание переменных
	int n = 0;
	int max_odd = 0;
	int c_even = 0;
	int An = 0;
	cin >> n;
	
	// цикл перебора элементов последовательности
	for (int i = 1; i <= n; i++) {
		cin >> An;
		if (An % 2 == 0) {
			c_even++;
		}
		else {
			if (An > max_odd) {
				max_odd = An;
			}
		}
	}

	// вывод результатов
	cout << "Максимальное нечетное: " << max_odd << endl;
	cout << "Кол-во четных: " << c_even << endl;
	return 0;
}
