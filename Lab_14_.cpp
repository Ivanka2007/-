#include <iostream>
#include <fstream>
using namespace std;

int** createMatrix(int n) {
    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
    }
    return A;
}

// Асиметричне відношення: якщо (i,j) ∈ R, то (j,i) ∉ R
bool isAsymmetric(int** A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 1 && A[j][i] == 1)
                return false;
    return true;
}

// Транзитивне відношення: якщо (i,j) ∈ R і (j,k) ∈ R, то (i,k) ∈ R
bool isTransitive(int** A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 1)
                for (int k = 0; k < n; k++)
                    if (A[j][k] == 1 && A[i][k] == 0)
                        return false;
    return true;
}

// Читання графа з файлу
void readGraph(const char* filename, int& n, int& m, int**& A) {
    ifstream fin(filename);
    fin >> n >> m;

    A = createMatrix(n);

    for (int i = 0; i < m; i++) {
        int v, u;
        fin >> v >> u;
        A[v - 1][u - 1] = 1;
    }

    fin.close();
}

int main() {
    int n, m;
    int** A;

    readGraph("lab14text.txt", n, m, A);

    cout << "Asymmetric: "
         << (isAsymmetric(A, n) ? "yes" : "no") << "\n";

    cout << "Transitive: "
         << (isTransitive(A, n) ? "yes" : "no") << "\n";

    // Очищення пам'яті
    for (int i = 0; i < n; i++)
        delete[] A[i];
    delete[] A;

    return 0;
}
