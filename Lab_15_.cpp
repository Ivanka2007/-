#include <iostream>
using namespace std;

const int MAXN = 20;   
int col[MAXN];        
int n;
int solutions = 0;

bool isSafe(int row, int c) {
    for (int i = 0; i < row; i++) {
        if (col[i] == c)
            return false;
        if (abs(col[i] - c) == abs(i - row))
            return false;
    }
    return true;
}

void backtrack(int row) {
    if (row == n) {
        solutions++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (isSafe(row, c)) {
            col[row] = c;
            backtrack(row + 1);
        }
    }
}

int main() {
    cout << "Enter n: ";
    cin >> n;

    backtrack(0);

    cout << "Number of solutions for " << n
        << "-queens: " << solutions << endl;

    return 0;
}