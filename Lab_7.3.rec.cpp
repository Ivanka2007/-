#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void PrintRow(int** a, const int rowNo, const int colCount, int colNo) {
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo) {
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void CreateRow(int** a, const int rowNo, const int colCount, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < colCount - 1)
        CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, colCount, Low, High, 0);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

bool IsMaxInRowN(int** a, const int rowNo, const int max, const int colCount, int colNo) {
    if (a[rowNo][colNo] > max)
        return false;
    if (colNo < colCount - 1)
        return IsMaxInRowN(a, rowNo, max, colCount, colNo + 1);
    else
        return true;
}

bool IsMinInColK(int** a, const int colNo, const int min, const int rowCount, int rowNo) {
    if (a[rowNo][colNo] < min)
        return false;
    if (rowNo < rowCount - 1)
        return IsMinInColK(a, colNo, min, rowCount, rowNo + 1);
    else
        return true;
}

void Part2_SaddlePointRow(int** a, const int rowCount, const int colCount, int& No, const int rowNo, int colNo) {
    if (IsMaxInRowN(a, rowNo, a[rowNo][colNo], colCount, 0) &&
        IsMinInColK(a, colNo, a[rowNo][colNo], rowCount, 0)) {
        cout << setw(4) << ++No << setw(6) << rowNo << setw(6) << colNo << endl;
    }
    if (colNo < colCount - 1)
        Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, colNo + 1);
}

void Part2_SaddlePointRows(int** a, const int rowCount, const int colCount, int& No, int rowNo) {
    Part2_SaddlePointRow(a, rowCount, colCount, No, rowNo, 0);
    if (rowNo < rowCount - 1)
        Part2_SaddlePointRows(a, rowCount, colCount, No, rowNo + 1);
}

void SortToDiagonal(int** a, const int n) {
    for (int d = 0; d < n; d++) {
        int maxI = d, maxJ = d;
        for (int i = d; i < n; i++) {
            for (int j = d; j < n; j++) {
                if (a[i][j] > a[maxI][maxJ]) {
                    maxI = i;
                    maxJ = j;
                }
            }
        }
        swap(a[d][d], a[maxI][maxJ]);
    }
}

int FirstRowWithoutPositive(int** a, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; i++) {
        bool hasPositive = false;
        for (int j = 0; j < colCount; j++) {
            if (a[i][j] > 0) {
                hasPositive = true;
                break;
            }
        }
        if (!hasPositive)
            return i;
    }
    return -1; 
}

int main() {
    srand((unsigned)time(NULL));
    int Low = -7;
    int High = 7;
    int rowCount, colCount;

    cout << "Введіть кількість рядків: "; cin >> rowCount;
    cout << "Введіть кількість стовпців: "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);

    cout << "Згенерована матриця:\n";
    PrintRows(a, rowCount, colCount, 0);

    if (rowCount == colCount) {
        SortToDiagonal(a, rowCount);
        cout << "Після розміщення найбільших елементів на головній діагоналі:\n";
        PrintRows(a, rowCount, colCount, 0);
    }

    int rowIndex = FirstRowWithoutPositive(a, rowCount, colCount);
    if (rowIndex != -1)
        cout << "Перший рядок без додатних елементів: " << rowIndex << endl;
    else
        cout << "Усі рядки мають додатні елементи." << endl;

    cout << "\nСідлові точки (максимум у рядку і мінімум у стовпці):\n";
    cout << setw(4) << "№" << setw(6) << "Ряд" << setw(6) << "Стовп" << endl;
    int No = 0;
    Part2_SaddlePointRows(a, rowCount, colCount, No, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}