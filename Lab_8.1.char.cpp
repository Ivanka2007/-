#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void CountSymbols(char* str, int& plus, int& minus, int& eq, int i = 1) {
    if (str[i] == '\0')
        return;
    if (str[i] == '+') plus++;
    if (str[i] == '-') minus++;
    if (str[i] == '=') eq++;
    CountSymbols(str, plus, minus, eq, i + 1);
}

char* ReplacePairs(char* s) {
    int len = strlen(s);
    char* result = new char[len * 2 + 1];
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if ((s[i] == '+' && s[i + 1] == '+') ||
            (s[i] == '-' && s[i + 1] == '-') ||
            (s[i] == '=' && s[i + 1] == '=')) {
            result[j++] = '*';
            result[j++] = '*';
            result[j++] = '*';
            i += 2;
        } else {
            result[j++] = s[i++];
        }
    }
    result[j] = '\0';
    strcpy(s, result);
    return result;
}

int main() {
    char str[201];
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 200);

    int plus = 0, minus = 0, eq = 0;
    CountSymbols(str, plus, minus, eq);

    cout << "\nКількість '+' : " << plus << endl;
    cout << "Кількість '-' : " << minus << endl;
    cout << "Кількість '=' : " << eq << endl;

    char* result = ReplacePairs(str);

    cout << "\nМодифікований рядок (параметр): " << str << endl;
    cout << "Модифікований рядок (результат): " << result << endl;

    delete[] result;
    return 0;
}