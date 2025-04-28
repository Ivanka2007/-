#include <iostream>
#include <string>
using namespace std;

void CountSymbols(const string& s, int& plus, int& minus, int& equal) {
    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == '+') plus++;
        if (s[i] == '-') minus++;
        if (s[i] == '=') equal++;
    }
}

string Change(string& s) {
    size_t pos = 0;
    while (pos < s.length() - 1) {
        if ((s[pos] == '+' && s[pos + 1] == '+') ||
            (s[pos] == '-' && s[pos + 1] == '-') ||
            (s[pos] == '=' && s[pos + 1] == '=')) {
            s.replace(pos, 2, "***");
            pos += 3;
        } else {
            pos++;
        }
    }
    return s;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    int plus = 0, minus = 0, equal = 0;
    CountSymbols(str, plus, minus, equal);

    cout << "\nКількість '+' : " << plus << endl;
    cout << "Кількість '-' : " << minus << endl;
    cout << "Кількість '=' : " << equal << endl;

    string result = Change(str);

    cout << "\nМодифікований рядок (параметр): " << str << endl;
    cout << "Модифікований рядок (результат): " << result << endl;

    return 0;
}
