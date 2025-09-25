#include <iostream>
using namespace std;

int main() {
	// ввод переменной
	int n = 0;
	cin >> n;

	int res = 0;

	for (int i = 1; i <= n; i++) {
		if (i % 2 == 0 or i % 5 == 0) {
			res += i;
		}
	}

	// выводи результат
	cout << "Результат: " << res << endl;

	return 0;
}
