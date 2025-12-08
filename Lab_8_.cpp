#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 100; 

int n; 
int adj[MAX][MAX]; 
bool visited[MAX];
int stackArr[MAX]; 
int top = -1;
int dfs_num = 0;

void push(int v) {
    if (top < MAX - 1) stackArr[++top] = v;
}

int pop() {
    if (top >= 0) return stackArr[top--];
    return -1;
}

bool isEmpty() {
    return top == -1;
}

void printStack() {
    for (int i = 0; i <= top; i++) {
        cout << stackArr[i] << " ";
    }
}

void DFS_iterative(int start) {
    push(start);

    cout << left << setw(10) << "DFS ¹"
        << setw(15) << "Ïîòî÷íà âåðøèíà"
        << "Âì³ñò ñòåêó" << endl;
    cout << string(40, '-') << endl;

    while (!isEmpty()) {
        int v = pop();

        if (!visited[v]) {
            visited[v] = true;
            dfs_num++;

            for (int i = n; i >= 1; i--) {
                if (adj[v][i] == 1 && !visited[i]) {
                    push(i);
                }
            }

            cout << left << setw(10) << dfs_num
                << setw(15) << v;
            printStack();
            cout << endl;
        }
    }
}


int main() {
    setlocale(LC_ALL, "ukr");

    ifstream fin("lab8text.txt");
    if (!fin.is_open()) {
        cout << "Не вдалося відкрити файл!" << endl;
        return 1;
    }

    fin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }
    fin.close();

    int start;
    cout << "Введіть початкову вершину: ";
    cin >> start;

    for (int i = 1; i <= n; i++) visited[i] = false;

    DFS_iterative(start);

    return 0;
}