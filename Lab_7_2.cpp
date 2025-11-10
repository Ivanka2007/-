#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;

const int MAX_N = 100;
const int MAX_M = 1000;

struct Edge {
    int from;
    int to;
};

struct Graph {
    int n;      
    int m;        
    bool directed;  
    Edge edges[MAX_M];
};

void findPendantAndIsolated(const Graph& g) {
    int inDegree[MAX_N] = { 0 };
    int outDegree[MAX_N] = { 0 };

    for (int i = 0; i < g.m; ++i) {
        int u = g.edges[i].from;
        int v = g.edges[i].to;

        outDegree[u]++;
        inDegree[v]++;

        if (!g.directed && u != v) {
            outDegree[v]++;
            inDegree[u]++;
        }
    }

    bool hasPendant = false;
    bool hasIsolated = false;

    cout << "\n--- Результати аналізу ---\n";

    for (int i = 0; i < g.n; ++i) {
        int deg = inDegree[i] + outDegree[i];

        if (deg == 1) {
            cout << "Висяча вершина: " << i << "\n";
            hasPendant = true;
        }
        if (deg == 0) {
            cout << "Ізольована вершина: " << i << "\n";
            hasIsolated = true;
        }
    }

    if (!hasPendant) cout << "Висячих вершин немає.\n";
    if (!hasIsolated) cout << "Ізольованих вершин немає.\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Graph g;
    string filename;

    cout << "Введіть назву файлу з графом (наприклад graph.txt): ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Помилка відкриття файлу!\n";
        return 1;
    }

    // Зчитування даних графа
    fin >> g.n >> g.m >> g.directed;
    for (int i = 0; i < g.m; ++i) {
        fin >> g.edges[i].from >> g.edges[i].to;
    }
    fin.close();

    cout << "\nГраф успішно зчитано.\n";

    // Запит користувача
    char choice;
    cout << "Бажаєте вивести список висячих та ізольованих вершин? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        findPendantAndIsolated(g);
    } else {
        cout << "Вивід скасовано користувачем.\n";
    }

    return 0;
}
