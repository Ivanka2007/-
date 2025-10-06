#include <iostream>
using namespace std;

void Print(int a[], int len);
void Init(int a[], int len);

int main() {
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;

    if (r > n || r < 0) {
        cout << "Invalid input!" << endl;
        return 1;
    }

    int comb[20];

    Init(comb, r);
    Print(comb, r);

    while (true) {
        int i = r - 1;

        while (i >= 0 && comb[i] == n - r + i + 1)
            i--;

        if (i < 0) break; 

        comb[i]++;

        for (int j = i + 1; j < r; j++)
            comb[j] = comb[j - 1] + 1;

        Print(comb, r);
    }

    return 0;
}

void Init(int a[], int len) {
    for (int i = 0; i < len; i++)
        a[i] = i + 1;
}

void Print(int a[], int len) {
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << "\n";
}