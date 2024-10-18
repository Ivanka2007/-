#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y, R;

    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;
    cout << "y = "; cin >> R;

    bool A = (x >= 0 && y >= 0 && pow(x, 2) + pow(y, 2) <= pow(R, 2));
    bool B = (x >= 0 && y >= 0 && pow(x, 2) + pow(y, 2) <= pow(R, 2));

    if (A || B) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}