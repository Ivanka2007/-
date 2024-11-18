#include <iostream>
#include <cmath>

using namespace std;

double h(const double x); // прототип

int main()
{
    double x;

    cout << "x = "; cin >> x;

    double c = (pow(h(x), 2) + 2 * h(1 + x + pow(x, 2))) / (1 + pow(h (x / 2), 3));
    cout << "result" << c;
    return 0;
}
double h(const double m) // визначення
{
    return (sin(m) + cos(m)) / (1 + m * m);
}