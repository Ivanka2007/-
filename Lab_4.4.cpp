#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double x, y, xp, xk, dx, R1, R2;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "R1 = "; cin >> R1;
    cout << "R2 = "; cin >> R2;

    cout << fixed;
    cout << "----------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
         << setw(7) << "y" << "    |" << endl;
    cout << "----------------------" << endl;
    x = xp;

    while (x <= xk)
    {
        if (x <= -6){
            y = R2 / 2;
        }
        else if (-6 < x && x <= -2 * R2) 
            y = (R2 / 2) + ((x + 6) * (0 - R2 / 2) / (-2 * R2 + 6));
        else if (-2 * R2 < x && x <= 0) 
            y = sqrt(pow(R2, 2) - pow(x + R2, 2));
        else if (0 < x && x <= 2 * R1) 
            y = -sqrt(pow(R1, 2) - pow(x - R1, 2));
        else {
            y = -R1 * (x - 2 * R1);
        }
        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(3) << y
            << " |" << endl;
        x += dx;
    }
    cout << "----------------------" << endl;
    return 0;
}