#include <iostream>
#include <cmath>
using namespace std;

int pascal(int row, int col) {
    // Базові умови
    if (row == 0 || col == 0 || row == col) {
        return 1;
    }
    // Рекурсивний виклик
    return pascal(row - 1, col - 1) + pascal(row - 1, col);
}

void printPascal(int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows;
    cout << "Введіть кількість рядків трикутника Паскаля: ";
    cin >> rows;

    printPascal(rows);

    return 0;
}