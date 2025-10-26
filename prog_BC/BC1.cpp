#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


// Функция ручного преобразования строки в число
double parseNumber(const char* str) {
    double result = 0.0;
    double fraction = 0.0;
    double divisor = 1.0;
    bool negative = false;
    bool afterDot = false;

    // Пропуск пробелов
    while (*str == ' ') str++;

    // Проверка знака
    if (*str == '-') {
        negative = true;
        str++;
    }
    else if (*str == '+') {
        str++;
    }

    // Основной цикл чтения числа
    while (*str != '\0' && *str != ';' && *str != '\n') {
        if (*str == '.') {
            afterDot = true;
        }
        else if (*str >= '0' && *str <= '9') {
            int digit = *str - '0';
            if (!afterDot) {
                result = result * 10 + digit;
            }
            else {
                divisor *= 10.0;
                fraction += digit / divisor;
            }
        }
        else {
            break;
        }
        str++;
    }

    result += fraction;
    if (negative) result = -result;
    return result;
}


// Функция извлечения значения по метке 
double extractValue(const std::string& line, const char* prt) {
    const char* p = line.c_str();
    const char* found = nullptr;

    // Поиск метки вручную
    while (*p != '\0') {
        const char* start = p;
        const char* lab = prt;
        while (*start && *lab && *start == *lab) {
            start++;
            lab++;
        }
        if (*lab == '\0') { // метка найдена
            found = start;
            break;
        }
        p++;
    }

    if (found) {
        return parseNumber(found);
    }
    else {
        return NAN; // если метка не найдена
    }
}

int main() {
    // прием данных
    const int n = 3;
    vector<string> logs = {
        "T:00:01;V:220.3;I:10.2;F:49.9",
        "T:00:02;V:219.7;I:10.4;F:50.0",
        "T:00:03;V:221.1;I:9.8;F:49.8"
    };

    std::cout << std::fixed << std::setprecision(1);
    vector<double> voltage, current, freq;
    vector<string> timeStamps;
    
    // Парсинг строк
    for (const auto& line : logs) {
        // Извлечение данных
        double v = extractValue(line, "V:");
        double i = extractValue(line, "I:");
        double f = extractValue(line, "F:");

        // Извлечение времени вручную
        const char* ts = line.c_str();
        const char* pos = nullptr;
        if ((pos = strstr(ts, "T:")) != nullptr) {
            pos += 2;
            string tstamp;
            while (*pos && *pos != ';') {
                tstamp.push_back(*pos);
                pos++;
            }
            timeStamps.push_back(tstamp);
        }

        voltage.push_back(v);
        current.push_back(i);
        freq.push_back(f);
    }

    double avg_p = 0;
    double avg_v = 0;
    vector<double> power;

    for (int i = 0; i < 3; i++) {
        double p = round(voltage[i] * current[i] * 10) / 10;
        
        power.push_back(p);
        avg_p += p;
        avg_v += voltage[i];
    }

    avg_p /= 3.0;
    avg_v /= 3.0;

    cout << "Average Power: " << avg_p << " W" << endl;

    double max_otkl_v = 0;
    for (int i = 0; i < 3; i++) {
        double curr_otkl = abs(voltage[i] - avg_v);
        if (curr_otkl > max_otkl_v) {
            max_otkl_v = curr_otkl;
        }
    }
    cout << "Voltage deviation max: " << max_otkl_v << " V" << endl;

    for (int i = 0; i < 3; i++) {
        if (abs(freq[i] - 50) >= 0.2) {
            cout << "Frequency deviation at T=" << timeStamps[i] << ": " << abs(freq[i] - 50) << " Hz" << endl;
        }
    }

    bool stable = true;
    for (int i = 0; i < 3; i++) {
        double curr_otkl = abs(voltage[i] - avg_v);
        if (abs(freq[i] - 50) >= 0.2 and curr_otkl != 0) {
            stable = false;
        }
    }

    if (stable) {
        cout << "System stable: true" << endl;
    }
    else {
        cout << "System stable: false" << endl;
    }
    

    return 0;
}
