#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void CountSymbols(char* str, int i, int& plus, int& minus, int& eq) {
    if (str[i] == '\0')
        return;
    if (str[i] == '+') plus++;
    if (str[i] == '-') minus++;
    if (str[i] == '=') eq++;
    CountSymbols(str, i + 1, plus, minus, eq);
}

char* Change(char* dest, const char* str, int i, int j) {
    if (str[i] == '\0') {
        dest[j] = '\0';
        return dest;
    }

    if ((str[i] == '+' && str[i + 1] == '+') ||
        (str[i] == '-' && str[i + 1] == '-') ||
        (str[i] == '=' && str[i + 1] == '=')) {
        dest[j++] = '*';
        dest[j++] = '*';
        dest[j++] = '*';
        return Change(dest, str, i + 2, j);
    }
    else {
        dest[j++] = str[i];
        return Change(dest, str, i + 1, j);
    }
}

int main() {
    char str[201];
    cout << "Введіть рядок:" << endl;
    cin.getline(str, 200);

    int plus = 0, minus = 0, eq = 0;
    CountSymbols(str, 1, plus, minus, eq);

    cout << "\nКількість '+' : " << plus << endl;
    cout << "Кількість '-' : " << minus << endl;
    cout << "Кількість '=' : " << eq << endl;

    char* dest = new char[401];
    Change(dest, str, 0, 0);

    cout << "\nМодифікований рядок: " << dest << endl;

    delete[] dest;
    return 0;
}