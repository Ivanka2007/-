#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    double x, y, R, x1, y1;
            srand((unsigned) time(NULL));
    cout << "R = "; cin >> R;
    for (int i = 1; i <= 10; i++) {
            cout << "x = "; cin >> x;
            cout << "y = "; cin >> y;

            bool A = (x <= 0 && x >= -R && y >= 0 && y <= R && pow(x, 2) + pow(y, 2) >= pow(R, 2));
		    bool B = (x >= 0 && y <= 0 && pow(x, 2) + pow(y, 2) <= pow(R, 2));

		    if (A || B) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
    }
    // random
    for (int i = 1; i <= 10; i ++) {
            x1 = -R + rand() * (R - (-R)) / RAND_MAX;
            y1 = -R + rand() * (R - (-R)) / RAND_MAX;

            bool A1 = (x1 <= 0 && x1 >= -R && y1 >= 0 && y1 <= R && pow(x1, 2) + pow(y1, 2) >= pow(R, 2));
	        bool B1 = (x1 >= 0 && y1 <= 0 && pow(x1, 2) + pow(y1, 2) <= pow(R, 2));

            if (A1 || B1) {
                cout << "No: " << "x1: " << x1 << " y2: " << y1 << endl;
            }
            else {
                cout << "No: " << "x1: " << x1 << " y2: " << y1 << endl;
            }
    }
    
    return 0;
}