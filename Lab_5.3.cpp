#include <iostream>
#include <cmath>

using namespace std;

double y(const double x); //прототип

int main()
{
    double fp, fk, z;
    int n;
    cout << "fp = "; cin >> fp;
    cout << "fk = "; cin >> fk;
    cout << "n = "; cin >> n;
    double fg = (fk - fp) / n;
    double f = fp;
    while (f <= fk)
    {
        z = y(f / 2) + pow(y(f + 1), 2) + y(2 * f);
        cout << f << " " << z << endl;
        f += fg;
    }
    return 0;
}

double y(const double x)
{
    if (abs(x) >= 1)
        return (exp(x) / (1 + exp(x)) + sin(x));
    else
    {
        double S = 0;
        int j = 0;
        double a = 1;
        S = a;
        do
        {
            j++;
            double R = -x * x / ((4 * pow(j, 2)) - (2 * j));
            a *= R;
            S += a;
        } while (j < 8);
        return S;
    }
}