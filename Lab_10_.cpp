#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MAX = 100;
const int INF = 9999;

// --- Зчитування графа зі списку ребер ---
bool LoadGraph(const char* filename, int graph[MAX][MAX], int& n, int& m)
{
    ifstream fin(filename);
    if (!fin.is_open())
        return false;

    fin >> n >> m;

    // Ініціалізація
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j ? 0 : INF);

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        fin >> v >> u >> w;
        graph[v - 1][u - 1] = w;
        graph[u - 1][v - 1] = w;   // бо граф НЕорієнтований
    }

    fin.close();
    return true;
}

// --- Вивід матриці ---
void PrintMatrix(int graph[MAX][MAX], int n)
{
    cout << "\nМатриця ваг:\n";
    cout << "     ";
    for (int j = 0; j < n; j++)
        cout << setw(5) << "v" << j + 1;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "v" << i + 1 << " ";
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                cout << setw(6) << "-";
            else
                cout << setw(6) << graph[i][j];
        }
        cout << endl;
    }
}

// --- Збереження у файл ---
bool SaveMatrixToFile(const char* filename, int graph[MAX][MAX], int n)
{
    ofstream fout(filename);
    if (!fout.is_open())
        return false;

    fout << "Матриця ваг:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                fout << "-" << " ";
            else
                fout << graph[i][j] << " ";
        }
        fout << endl;
    }

    fout.close();
    return true;
}

// --- Головна програма ---
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int graph[MAX][MAX];
    int n, m;

    if (!LoadGraph("lab10_text.txt", graph, n, m))
    {
        cout << "Помилка відкриття файлу lab10_text.txt" << endl;
        return 1;
    }

    PrintMatrix(graph, n);

    char outFile[100];
    cout << "\nВведіть назву файлу для збереження матриці: ";
    cin >> outFile;

    if (SaveMatrixToFile(outFile, graph, n))
        cout << "Матрицю успішно збережено у " << outFile << endl;
    else
        cout << "Помилка при записі у файл!" << endl;

    return 0;
}