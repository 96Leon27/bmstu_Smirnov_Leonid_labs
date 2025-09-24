#include <iostream>
using namespace std;

int main() {
	// создаем переменную для цикла (пока не будет введен ctrl + D), саму переменную буквы и переменную подсчета
	bool fl = true;
	char let = ' ';
	int n = 0;

	int gl[] = { 97, 65, 101, 69, 117, 85, 121, 89, 111, 79 };

	while (fl) {
		cin >> let;

		// если вводят ctrl + D, то заканчиваем
		if ((int)let != 4) {
			// проходимся по массиву и анализируем совпадения
			bool is_in = false;
			for (int i = 0; i < 12; i++) {
				if (gl[i] == (int)let) {
					is_in = true;
				}
			}

			if (is_in) {
				n += 1;
			}
		} else {
			fl = false;
		}
	}

	// выводи результат
	cout << "Кол-во гласных: " << n << endl;

	return 0;
}
