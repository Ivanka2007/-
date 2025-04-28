// Lab_7_2_2.cpp
// Чичерська
// Лабораторна робота № 7.2.2
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 37

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void CreateRow(int** a, int row, int n, int Low, int High, int col) {
    a[row][col] = Low + rand() % (High - Low + 1);
    if (col < n - 1)
        CreateRow(a, row, n, Low, High, col + 1);
}

void CreateMatrix(int** a, int k, int n, int Low, int High, int row) {
    CreateRow(a, row, n, Low, High, 0);
    if (row < k - 1)
        CreateMatrix(a, k, n, Low, High, row + 1);
}

void PrintRow(int** a, int row, int n, int col) {
    cout << setw(4) << a[row][col];
    if (col < n - 1)
        PrintRow(a, row, n, col + 1);
    else
        cout << endl;
}

void PrintMatrix(int** a, int k, int n, int row) {
    PrintRow(a, row, n, 0);
    if (row < k - 1)
        PrintMatrix(a, k, n, row + 1);
}

int MinInRow(int* row, int n, int col = 0, int minVal = INT_MAX) {
    if (col == n)
        return minVal;
    if (row[col] < minVal)
        minVal = row[col];
    return MinInRow(row, n, col + 1, minVal);
}

int SumOfRowMins(int** a, int k, int n, int row = 0) {
    if (row == k)
        return 0;
    return MinInRow(a[row], n) + SumOfRowMins(a, k, n, row + 1);
}

int main() {
    srand((unsigned)time(NULL));

    int k, n;
    cout << "Введіть кількість рядків (k): ";
    cin >> k;
    cout << "Введіть кількість стовпців (n): ";
    cin >> n;

    int Low = 10, High = 50;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    CreateMatrix(a, k, n, Low, High, 0);
    cout << "\nМатриця:\n";
    PrintMatrix(a, k, n, 0);

    int sum = SumOfRowMins(a, k, n);
    cout << "\nСума мінімальних елементів у кожному рядку: " << sum << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
