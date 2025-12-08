#include <iostream>
#include <fstream>

const int MAXN = 100;
int g[MAXN][MAXN]; 
int color[MAXN];  
int n, m;          

bool readGraph(const std::string& filename) {
    std::ifstream fin(filename);
    if (!fin) {
        std::cerr << "Cannot open file\n";
        return false;
    }

    fin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        g[u - 1][v - 1] = 1; 
    }

    return true;
}

void greedyColoring() {
    for (int i = 0; i < n; i++)
        color[i] = -1;

    color[0] = 0;
    bool available[MAXN];

    for (int u = 1; u < n; u++) {
        for (int i = 0; i < n; i++) available[i] = true;

        for (int v = 0; v < n; v++) {
            if ((g[u][v] || g[v][u]) && color[v] != -1)
                available[color[v]] = false;
        }

        int cr;
        for (cr = 0; cr < n; cr++)
            if (available[cr]) break;
        color[u] = cr;
    }
}

void printResult() {
    int maxColor = -1;
    for (int i = 0; i < n; i++)
        if (color[i] > maxColor)
            maxColor = color[i];

    std::cout << "Minimum number of colors needed: " << maxColor + 1 << "\n";
    std::cout << "Vertex : Color\n";
    for (int i = 0; i < n; i++)
        std::cout << i + 1 << " : " << color[i] + 1 << "\n";
}

void writeResult(const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout) {
        std::cerr << "Cannot open output file\n";
        return;
    }

    int maxColor = -1;
    for (int i = 0; i < n; i++)
        if (color[i] > maxColor)
            maxColor = color[i];

    fout << "Minimum number of colors needed: " << maxColor + 1 << "\n";
    fout << "Vertex : Color\n";
    for (int i = 0; i < n; i++)
        fout << i + 1 << " : " << color[i] + 1 << "\n";
}

int main() {
    std::string inputFile = "lab13text.txt";
    std::string outputFile = "lab13output.txt";

    if (!readGraph(inputFile)) return 1;

    greedyColoring();
    printResult();
    writeResult(outputFile);

    return 0;
}