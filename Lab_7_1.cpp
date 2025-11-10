#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

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

void calculateDegrees(const Graph& g, ostream& out) {
    int inDegree[MAX_N] = { 0 };
    int outDegree[MAX_N] = { 0 };

    for (int i = 0; i < g.m; i++) {
        int u = g.edges[i].from;
        int v = g.edges[i].to;

        outDegree[u]++;
        inDegree[v]++;

        if (!g.directed && u != v) {
            outDegree[v]++;
            inDegree[u]++;
        }
    }

    std::cout << "Вершина\tВихідний\tВхідний\n";
    for (int i = 0; i < g.n; i++) {
        out << setw(5) << i << "\t" << setw(8) << outDegree[i]
            << "\t" << setw(8) << inDegree[i] << "\n";
    }

    bool homogeneous = true;
    int degree = outDegree[0] + inDegree[0];
    for (int i = 1; i < g.n; i++) {
        if (outDegree[i] + inDegree[i] != degree) {
            homogeneous = false;
            break;
        }
    }

    if (homogeneous)
        out << "\nГраф однорідний. Степінь однорідності: " << degree << "\n";
    else
        out << "\nГраф не однорідний.\n";
}

void findPendantAndIsolated(const Graph& g, ostream& out) {
    int inDegree[MAX_N] = { 0 };
    int outDegree[MAX_N] = { 0 };

    for (int i = 0; i < g.m; i++) {
        int u = g.edges[i].from;
        int v = g.edges[i].to;

        outDegree[u]++;
        inDegree[v]++;

        if (!g.directed && u != v) {
            outDegree[v]++;
            inDegree[u]++;
        }
    }

    out << "\nІзольовані вершини: ";
    bool hasIsolated = false;
    for (int i = 0; i < g.n; i++) {
        if (inDegree[i] + outDegree[i] == 0) {
            out << i << " ";
            hasIsolated = true;
        }
    }
    if (!hasIsolated) out << "немає.";

    out << "\nВисячі вершини: ";
    bool hasPendant = false;
    for (int i = 0; i < g.n; i++) {
        if (inDegree[i] + outDegree[i] == 1) {
            out << i << " ";
            hasPendant = true;
        }
    }
    if (!hasPendant) out << "немає.";
    out << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Graph g;

    string filename;
    cout << "Введіть назву вхідного файлу (наприклад: graph.txt): ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Помилка відкриття файлу!\n";
        return 1;
    }

    fin >> g.n >> g.m >> g.directed;
    for (int i = 0; i < g.m; i++) {
        fin >> g.edges[i].from >> g.edges[i].to;
    }
    fin.close();

    cout << "\n--- Результат ---\n";
    calculateDegrees(g, cout);
    findPendantAndIsolated(g, cout);

    char choice;
    cout << "\nЗаписати результати у файл? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        ofstream fout("result.txt");
        calculateDegrees(g, fout);
        findPendantAndIsolated(g, fout);
        fout.close();
        cout << "Результати збережено у файл result.txt\n";
    }

    return 0;
}