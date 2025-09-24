#include <iostream>
using namespace std;

int main() {
	// ввод переменной возраста
	int age = 0;
	cin >> age;

	// выводим результат в зависимости от возраста
	if (age <= 0) {
		cout << "Возраст некорректен" << endl;
	} else if (age < 18) {
		cout << "Вы еще несовершеннолетний" << endl;
	} else if (age <= 60) {
		cout << "Вы взрослый человек" << endl;
	} else if (age <= 120) {
		cout << "Вы пенсионер" << endl;
	} else {
		cout << "Вы еще живы?" << endl;
	}
	return 0;
}
