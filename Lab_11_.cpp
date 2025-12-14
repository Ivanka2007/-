#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

const int MAX = 100;
const int INF = 9999;

// ---- 1. Зчитування графа ----
bool LoadGraphFromFile(const char* filename, int graph[MAX][MAX], int& n)
{
    ifstream fin(filename);
    if (!fin.is_open())
     return false;

    int m;    // кількість ребер
    fin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = (i == j ? 0 : INF);

     // Зчитуємо m ребер у форматі: u v w
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        u--; v--;                 // робимо 0-based
        graph[u][v] = w;          // орієнтований граф
    }

    fin.close();
    return true;
}

// ---- 2. Алгоритм Флойда-Воршелла ----
void FloydWarshall(int graph[MAX][MAX], int next[MAX][MAX], int n)
{
    // next[i][j] вказує наступну вершину на найкоротшому шляху
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j] != INF && i != j)
                next[i][j] = j;
            else
                next[i][j] = -1;

    // Флойд
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                    next[i][j] = next[i][k];
                }
}

// ---- 3. Вивід матриці ----
void PrintMatrix(int graph[MAX][MAX], int n)
{
    cout << "\nМатриця найкоротших відстаней:\n";
    cout << "     ";

    for (int j = 0; j < n; j++)
        cout << setw(6) << "v" << j + 1;

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "v" << i + 1 << " ";
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                cout << setw(7) << "-";
            else
                cout << setw(7) << graph[i][j];
        }
        cout << endl;
    }
}

// ---- 4. Функція виводу маршруту ----
void PrintPath(int next[MAX][MAX], int start, int end)
{
    if (next[start][end] == -1)
    {
        cout << "Шляху не існує!" << endl;
        return;
    }

    cout << "Маршрут: v" << start + 1 << " ";

    int u = start;
    while (u != end)
    {
        u = next[u][end];
        cout << "→ v" << u + 1 << " ";
    }
    cout << endl;
}

// ---- 5. Основна програма ----
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    int graph[MAX][MAX];
    int nextV[MAX][MAX];

    if (!LoadGraphFromFile("lab11text.txt", graph, n))
    {
        cout << "Помилка відкриття файлу lab11text.txt!" << endl;
        return 1;
    }

    FloydWarshall(graph, nextV, n);
    PrintMatrix(graph, n);

    int start, end;
    cout << "\nВведіть початкову вершину: ";
    cin >> start;

    cout << "Введіть кінцеву вершину: ";
    cin >> end;

    start--;  
    end--;

    if (graph[start][end] == INF)
        cout << "Шляху між вершинами немає.\n";
    else
    {
        cout << "Найкоротша відстань: " << graph[start][end] << endl;
        PrintPath(nextV, start, end);
    }

    return 0;
}