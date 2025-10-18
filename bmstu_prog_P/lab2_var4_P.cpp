#include <iostream>
#include <vector>
#include <string>
using namespace std;


int div_words(const char* a, char words[][50]) {

    int wc = 0;
    int charInd = 0;

    for (int i = 0; a[i] != '\0' && wc < 10; i++) {
        if (a[i] != ' ' && a[i] != '\t' && a[i] != '\n') {
            words[wc][charInd++] = a[i];
        }
        else {
            words[wc][charInd] = '\0';
            wc++;
            charInd = 0;
        }
    }
    if (wc < 10) {
        words[wc][charInd] = '\0';
        wc++;
    }
    return wc;
}

int main() {
    char inp[500];
    char words[10][50];
    cout << "Введите 10 слов на латинице ";
    cin.getline(inp, 500);

    int wc = div_words(inp, words);
    if (wc < 10) {
        cout << "Слов меньше 10";
    }

    int cb = 0;
    for (int i = 0; i < wc; i++) {
        int len = strlen(words[i]);
        if (len > 0 && words[i][len - 1] == 'b') {
            cb++;
        }
    }
    cout << "Кол-во слов, оканчивающихся на b: " << cb << endl;


    int mxl = strlen(words[0]);
    for (int i = 0; i < wc; i++) {
        int l = strlen(words[i]);
        if (l > mxl) {
            mxl = l;
        }
    }
    cout << "Длина самого длинного слова: " << mxl << endl;


    char* lw = words[wc - 1];
    int cd = 0;
    for (int i = 0; i != strlen(lw); i++) {
        if (lw[i] == 'd') {
            cd++;
        }
    }
    cout << "Количество букв d в последнем слове: " << cd << endl;

    char upw[500];
    strcpy_s(upw, inp);
    for (int i = 0; i != strlen(upw); i++) {
        upw[i] = toupper(upw[i]);
    }
    cout << "Строка в верхнем регистре: " << upw << endl;

    int c = 0;
    for (int i = 0; i < wc; i++) {
        int ln = strlen(words[i]);
        if (ln >= 2) {
            if (words[i][1] == words[i][ln - 2]) {
                c++;
            }
        }
    }
    cout << "Количество слов с одинаковым вторым и предпоследним символом: " << c << endl;

}
