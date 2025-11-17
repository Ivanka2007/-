#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int MAX = 100;

bool LoadGraph(const char* filename, int graph[MAX][MAX], int& n)
{
    ifstream fin(filename);
    if (!fin.is_open())
        return false;

    fin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> graph[i][j];
    fin.close();
    return true;
}


void BFS(int graph[MAX][MAX], int n, int start, int bfs_number[MAX])
{
    bool visited[MAX] = { false };
    int queue[MAX];
    int front = 0, rear = 0;
    int counter = 1;

    for (int i = 0; i < n; i++)
        bfs_number[i] = -1;

    visited[start] = true;
    bfs_number[start] = counter++;
    queue[rear++] = start;

    cout << "²òåðàö³ÿ\tÏîòî÷íà âåðøèíà\tBFS-íîìåð\t×åðãà\n";
    cout << "-------------------------------------------------------\n";

    int iteration = 1;

    while (front < rear)
    {
        int v = queue[front++];

        cout << iteration++ << "\t\t" << v + 1 << "\t\t" << bfs_number[v] << "\t\t";
        for (int i = front; i < rear; i++)
            cout << queue[i] + 1 << " ";
        cout << endl;

        for (int u = 0; u < n; u++)
        {
            if (graph[v][u] == 1 && !visited[u])
            {
                visited[u] = true;
                bfs_number[u] = counter++;
                queue[rear++] = u;
            }
        }
    }

    cout << "\nПорядок обходу: ";
    for (int i = 0; i < n; i++)
        if (bfs_number[i] != -1)
            cout << i + 1 << " ";
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int graph[MAX][MAX];
    int n;

    if (!LoadGraph("lab9_text.txt", graph, n))
    {
        cout << "Помилка відкриття файлу graph.txt" << endl;
        return 1;
    }

    int start;
    cout << "Введіть початкову вершину (1-" << n << "): ";
    cin >> start;

    int bfs_number[MAX];
    BFS(graph, n, start - 1, bfs_number);

    return 0;
}