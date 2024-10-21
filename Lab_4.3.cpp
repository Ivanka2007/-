#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double x, a, b, c, xp, xk, dx, F;

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
         << setw(7) << "y" << "    |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        if (x < 0 && b != 0) {
            F = -a * pow(x, 2) + b;
        }
        else if (x > 0 && b == 0) {
            F = (x / (x - c )) + 5.5;
        }
        else {
            F = x / (-c);
        }


        cout << "|" << setw(7) << setprecision(2) << x
             << " |" << setw(10) << setprecision(3) << F
             << " |" << endl;

        x += dx;
    }
    cout << "---------------------------" << endl;
    return 0;
}