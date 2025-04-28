#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void CountSymbols(const char* str, int& plus, int& minus, int& eq) {
    plus = minus = eq = 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] == '+') plus++;
        if (str[i] == '-') minus++;
        if (str[i] == '=') eq++;
    }
}

char* ReplacePairs(const char* str) {
    size_t len = strlen(str);
    char* result = new char[len * 2 + 1];
    char* resPtr = result;

    for (size_t i = 0; i < len;) {
        if ((str[i] == '+' && str[i + 1] == '+') ||
            (str[i] == '-' && str[i + 1] == '-') ||
            (str[i] == '=' && str[i + 1] == '=')) {
            *resPtr++ = '*';
            *resPtr++ = '*';
            *resPtr++ = '*';
            i += 2;
        }
        else {
            *resPtr++ = str[i++];
        }
    }
    *resPtr = '\0';
    return result;
}

int main() {
    char str[201];
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 200);

    int plus, minus, eq;
    CountSymbols(str, plus, minus, eq);

    cout << "\nКількість '+' : " << plus << endl;
    cout << "Кількість '-' : " << minus << endl;
    cout << "Кількість '=' : " << eq << endl;

    char* modified = ReplacePairs(str);
    cout << "\nМодифікований рядок: " << modified << endl;

    delete[] modified;
    return 0;
}