// < Чичерська Іванна >
// Лабораторна робота № 3.1
// Розгалуження, задане формулою: функція однієї змінної.
// Варіант 0.1
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x = 0;
    double y = 0;
    double a = 0;
    double b = 0;
    cout << "Enter x: ";
    cin >> x;
    y = 4 * x - 7;
    // Скорочене розгалуження
    if (x < 0) {
        a = pow(x, 2) - 5 * x;
    }
    if (x >= 0 && x < 3) {
        a = atan((x + 4) / 8);
    }
    if (x >= 3) {
        a = pow(x, 3) + exp(2 * x + 3);
    }

    cout << "Result (shortened form) y: " << y + a << endl;

    // Повне розгалуження
    if (x < 0) {
        b = pow(x, 2) - 5 * x;
    }
    else if (x >= 0 && x < 3) {
        b = atan((x+4) / 8);
    }
    else {
        b = pow(x, 3) + exp(2 * x + 3);
    }

    cout << "Result (full form) y: " << y + b << endl;
    return 0;
}