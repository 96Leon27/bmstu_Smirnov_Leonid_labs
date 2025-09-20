#include <iostream>
using namespace std;


int main() {

    // вводим размеры массива
    const int size = 10;

    // создаем и заполняем массив данными
    int numbers[size];
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": " << endl;
        cin >> numbers[i];
    }

    // переменная суммы элементов
    int num_sum = 0;

    // переменная максимума последовательности
    int mx_el = numbers[0];

    for (int i = 0; i < size; i++) {
        // вывод элементов последовательности
        cout << i + 1 << " элемент последовательности: " << numbers[i] << endl;

        // подсчет суммы элементов последовательности
        num_sum += numbers[i];

        // поиск максимального элемента последовательности
        if (numbers[i] > mx_el){
            mx_el = numbers[i];
        }
    }

    // сортировка вставками
    int i, temp, j;
    for (i = 1; i < size; i++) {
        temp = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] < temp) {
            numbers[j + 1] = numbers[j];
            j = j - 1;
        }
        numbers[j + 1] = temp;
    }

    // вывод отсортированных элементов последовательности:
    cout << "\nОтсортированная последовательность:" << endl;
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " элемент последовательности: " << numbers[i] << endl;
    }
    
    // вывод результатов
    cout << "Сумма элементов последовательности: " << num_sum << endl;
    cout << "Максимальный элемент последовательности: " << mx_el << endl;

    return 0;
}
