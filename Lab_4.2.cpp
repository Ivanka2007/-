#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x, xp, xk, dx, A, B, y;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;

    cout << fixed;
    cout << "---------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
         << setw(7) << "y" << "     |" << endl;
    cout << "---------------------------" << endl;

    x = xp;
    A = 4 * x - 7;
    while (x <= xk)
    {
        if (x < 0) {
            B = pow(x, 2) - 5 * x;
        }
        else if (x >= 0 && x < 3) {
            B = atan(x + 4) / 8;
        }
        else {
            B = pow(x, 3) + exp(2 * x + 3);
        }
        y = A + B;

        cout << "|" << setw(7) << setprecision(2) << x
             << " |" << setw(10) << setprecision(3) << y
             << " |" << endl;

        x += dx;
    }
    
    cout << "---------------------------" << endl;
    return 0;
}
