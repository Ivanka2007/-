#include <iostream>
using namespace std;

int main() {
    double a, b, c, x;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter x: ";
    cin >> x;

    // Скорочене розгалуження
    double F1;
    if (x < 0 && b !=0) {
        F1 = -a * x * x + b;
    }
    if (x > 0 && b ==0) {
        F1 = x / (x - c) + 5.5;
    }
    if (!(x < 0 && b != 0) && !(x > 0 && b == 0)) {
        F1 = x / -c;
    }

    // Повне розгалуження
    double F2;
    if (x < 0 && b !=0) {
        F2 = -a * x * x + b;
    }
    else if (x > 0 && b == 0) {
        F2 = x / (x - c) + 5.5;
    }
    else {
        F2 = x / -c;
    }

    cout << "Result (shortened form): F = " << F1 << endl;
    cout << "Result (full form): F = " << F2 << endl;

    return 0;

}