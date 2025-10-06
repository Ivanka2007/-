#include <iostream>
#include <iomanip>
using namespace std;

int CalculateNByValue(int value);

int main() {
    int i;
    int width = 15;
    cout << "Enter i: ";
    cin >> i;

    int n = CalculateNByValue(i);
    long S[50][50]; 
    long B[50]; 

    for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= n; k++) {
            S[j][k] = 0;
        }
        B[j] = 0;
    }

    for (int j = 1; j <= n; j++) {
        S[j][1] = 1;
        S[j][j] = 1;
    }

    for (int j = 2; j <= n; j++) {
        for (int k = 2; k < j; k++) {
            S[j][k] = S[j - 1][k - 1] + k * S[j - 1][k];
        }
    }

    for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= j; k++) {
            B[j] += S[j][k];
        }
    }

    cout << "\nTable n = " << n << "\n\n";

    cout << setw(4) << "n\\k" << " |";
    for (int k = 1; k <= n; k++) {
        cout << setw(width) << k;
    }
    cout << " |" << setw(width) << "B(n)" << endl;

    cout << string(6 + n * width + width, '-') << endl;

    for (int j = 1; j <= n; j++) {
        cout << setw(4) << j << " |";
        for (int k = 1; k <= n; k++) {
            if (S[j][k] != 0)
                cout << setw(width) << S[j][k];
            else
                cout << setw(width) << " ";
        }
        cout << " |" << setw(width) << B[j] << endl;
    }

    return 0;
}

int CalculateNByValue(int value) {
    return value + 5;
}