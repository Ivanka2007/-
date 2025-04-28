#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;

void CreateRows(int** a, const int rowCount, const int colCount, const int Low, const int High, int rowNo = 0) {
    for (int j = 0; j < colCount; j++)
        a[rowNo][j] = Low + rand() % (High - Low + 1);
    if (rowNo < rowCount - 1)
        CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

void PrintRows(int** a, const int rowCount, const int colCount, int rowNo = 0) {
    for (int j = 0; j < colCount; j++)
        cout << setw(4) << a[rowNo][j];
    cout << endl;
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
}

void CountPositiveInZeroCols(int** a, const int rowCount, const int colCount, int& count, bool& found, int colNo = 0) {
    bool hasZero = false;
    for (int i = 0; i < rowCount; i++) {
        if (a[i][colNo] == 0) {
            hasZero = true;
            break;
        }
    }
    if (hasZero) {
        for (int i = 0; i < rowCount; i++) {
            if (a[i][colNo] > 0)
                count++;
        }
        found = true;
    }
    if (colNo < colCount - 1)
        CountPositiveInZeroCols(a, rowCount, colCount, count, found, colNo + 1);
}

bool IsMaxInRow(int** a, int row, int col, int colCount) {
    for (int j = 0; j < colCount; j++)
        if (a[row][j] > a[row][col])
            return false;
    return true;
}

bool IsMinInCol(int** a, int row, int col, int rowCount) {
    for (int i = 0; i < rowCount; i++)
        if (a[i][col] < a[row][col])
            return false;
    return true;
}

void PrintSaddlePoints(int** a, int rowCount, int colCount) {
    cout << "Сідлові точки (макс у рядку і мін у стовпці):\n";
    cout << setw(4) << "№" << setw(6) << "Ряд" << setw(6) << "Стовп" << endl;
    int num = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            if (IsMaxInRow(a, i, j, colCount) && IsMinInCol(a, i, j, rowCount))
                cout << setw(4) << ++num << setw(6) << i << setw(6) << j << endl;
}

void FillDiagonalWithMaxElements(int** a, const int n) {
    int* all = new int[n * n];
    int idx = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            all[idx++] = a[i][j];

    sort(all, all + n * n, greater<int>());

    for (int i = 0; i < n; i++)
        a[i][i] = all[i];

    delete[] all;
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
    int rowCount, colCount;
    int Low = -10, High = 10;

    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;

    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High);
    cout << "\nЗгенерована матриця:\n";
    PrintRows(a, rowCount, colCount);

    int count = 0;
    bool found = false;
    CountPositiveInZeroCols(a, rowCount, colCount, count, found);
    if (found)
        cout << "\nКількість додатних елементів у стовпцях з нулем: " << count << endl;
    else
        cout << "\nЖодного нуля у стовпцях не знайдено." << endl;

    cout << endl;
    PrintSaddlePoints(a, rowCount, colCount);

    if (rowCount == colCount) {
        FillDiagonalWithMaxElements(a, rowCount);
        cout << "\nМатриця після перестановки max елементів на головну діагональ:\n";
        PrintRows(a, rowCount, colCount);
    }

    int rowIdx = FirstRowWithoutPositive(a, rowCount, colCount);
    if (rowIdx != -1)
        cout << "\nПерший рядок без додатних елементів: " << rowIdx << endl;
    else
        cout << "\nУсі рядки містять додатні елементи." << endl;

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
