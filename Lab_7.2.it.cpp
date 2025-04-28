// Lab_7_2_1.cpp
// Чичерська
// Лабораторна робота № 7.2.1
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 37

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
bool SumOfMinInRows(int** a, const int n);

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n) {
    cout << "\nМатриця:\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int SumOfMinInRows(int** a, const int k, const int n) {
    int sum = 0;
    for (int i = 0; i < k; i++) {
        int minInRow = a[i][0];
        for (int j = 1; j < n; j++) {
            if (a[i][j] < minInRow)
                minInRow = a[i][j];
        }
        sum += minInRow;
    }
    return sum;
}

int main() {
    srand((unsigned)time(NULL));

    int Low = 1;
    int High = 50;

    int k, n;
    cout << "Введіть кількість рядків (k): ";
    cin >> k;
    cout << "Введіть кількість стовпців (n): ";
    cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);

    int sum = SumOfMinInRows(a, k, n);
    cout << "Сума мінімальних елементів у кожному рядку: " << sum << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
