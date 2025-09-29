#include <iostream>
#include <cmath>
using namespace std;

int main() {

	// задание переменных
	int n = 0;
	int res = 0;
	int An = 0;
	cin >> n;
	
	// цикл перебора элементов последовательности и степени двойки
	for (int i = 1; i <= n; i++) {
		cin >> An;
		if (An > pow(2, i)) {
			res++;
		}
	}

	// вывод результатов
	cout << "Результат: " << res << endl;
	return 0;
}
