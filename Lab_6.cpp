#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 1000;

void fillAdjacencyMatrixEdges(int adjMatrix[MAX_N][MAX_N], int edgesU[MAX_M], int edgesV[MAX_M], int m)
{
    for (int i = 0; i < m; i++)
        adjMatrix[edgesU[i] - 1][edgesV[i] - 1] = 1;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n, m;
    int edgesU[MAX_M], edgesV[MAX_M];
    int adjMatrix[MAX_N][MAX_N];
    int incMatrix[MAX_N][MAX_M];

    string inputFile, outputFile;

    cout << "Введіть назву файлу з графом (наприклад graph.txt): ";
    cin >> inputFile;

    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Помилка: не вдалося відкрити файл!\n";
        return 1;
    }

    fin >> n >> m;
    for (int i = 0; i < m; i++)
        fin >> edgesU[i] >> edgesV[i];
    fin.close();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            incMatrix[i][j] = 0;

    fillAdjacencyMatrixEdges(adjMatrix, edgesU, edgesV, m);

    for (int i = 0; i < m; i++) {
        int u = edgesU[i] - 1;
        int v = edgesV[i] - 1;
        incMatrix[u][i] = -1; 
        incMatrix[v][i] = 1;
    }

    cout << "Введіть назву файлу для запису результатів (наприклад output.txt): ";
    cin >> outputFile;
    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Помилка: не вдалося створити файл!\n";
        return 1;
    }

    cout << "\nМатриця суміжності:\n";
    fout << "Матриця суміжності:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(3) << adjMatrix[i][j];
            fout << setw(3) << adjMatrix[i][j];
        }
        cout << "\n";
        fout << "\n";
    }

    cout << "\nМатриця інцидентності:\n";
    fout << "\nМатриця інцидентності:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(3) << incMatrix[i][j];
            fout << setw(3) << incMatrix[i][j];
        }
        cout << "\n";
        fout << "\n";
    }

    fout.close();
    cout << "\nРезультати також записано у файл: " << outputFile << endl;
    return 0;
}