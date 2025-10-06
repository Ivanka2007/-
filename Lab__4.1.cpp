#include <iostream>
#include <algorithm> // для reverse
using namespace std;

void Init(int perm[], int n);
void Print(int a[], int len);

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int perm[20]; 
    Init(perm, n);

    Print(perm, n);

    while (true) {
        int j = n - 2;

        while (j >= 0 && perm[j] >= perm[j + 1]) j--;

        if (j < 0) break;

        int k = n - 1;
        while (perm[k] <= perm[j]) k--;

        swap(perm[j], perm[k]);

        int left = j + 1, right = n - 1;
        while (left < right) {
            swap(perm[left], perm[right]);
            left++;
            right--;
        }

        Print(perm, n);
    }

    return 0;
}

void Init(int perm[], int n) {
    for (int i = 0; i < n; i++)
        perm[i] = i + 1;
}

void Print(int a[], int len) {
    for (int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout << "\n";
}