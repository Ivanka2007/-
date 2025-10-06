#include <iostream>
using namespace std;

long Calculate(int n, int r);

int main() {
    int n, r;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter r: ";
    cin >> r;

    long A = Calculate(n, r);

    cout << "Result A(" << n << "," << r << ") = " << A << endl;

    return 0;
}

long Calculate(int n, int r) {
    long long P1 = 1, P2 = 1;

    for (int i = 1; i <= n; i++) {
        P1 *= i;
    }

    for (int i = 1; i <= n - r; i++) {
        P2 *= i;
    }

    return P1 / P2;
}