#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, R1, R2, y;
    cout << "R1 = "; cin >> R1;
    cout << "R2 = "; cin >> R2;
    cout << "x = "; cin >> x;

    if (x <= -6) {
        y = -R2 / 2;
    }
    else if (-6 < x && x <= -2 * R2) {
        y = (R2 / 2) + ((x + 6) * (0 - R2 / 2) / (-2 * R2 + 6));
    }
    else if (-2 * R2 < x && x <= 0) {
        y = sqrt(pow(R2, 2) - pow(x + R2, 2));
    }
    else if (0 < x && x <= 2 * R1) {
        y = -sqrt(pow(R1, 2) - pow(x - R1, 2));
    }
    else if (2 * R1 < x && x < 2 * R1 + 1) {
        y = R1 * (x - 2 * R1);
    }
    else {
        y = R1 * (2 * R1 + 1 -x);
    }

    cout << "y = " << y << endl;

    return 0;
}