#include <iostream>
#include <algorithm>
#include <windows.h>

using namespace std;

int CalculateAnd(int first, int second);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n;
    cout << "Введіть розмір універсуму n: ";
    cin >> n;

    int U[100];  
    int A[100]; 
    int B[100]; 
    int Abit[100], Bbit[100];
    int notA[100], AperB[100], AobB[100], ArizB[100], AxorB[100];

    cout << "Введіть елементи універсуму: ";
    for (int i = 0; i < n; i++) cin >> U[i];

    int ka;
    cout << "Введіть кількість елементів множини A: ";
    cin >> ka;
    cout << "Введіть елементи множини A: ";
    for (int i = 0; i < ka; i++) cin >> A[i];

    int kb;
    cout << "Введіть кількість елементів множини B: ";
    cin >> kb;
    cout << "Введіть елементи множини B: ";
    for (int i = 0; i < kb; i++) cin >> B[i];

    sort(U, U + n);

    for (int i = 0; i < n; i++) {
        Abit[i] = 0;
        Bbit[i] = 0;

        for (int j = 0; j < ka; j++)
            if (U[i] == A[j]) Abit[i] = 1;

        for (int j = 0; j < kb; j++)
            if (U[i] == B[j]) Bbit[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        notA[i] = 1 - Abit[i];                      // ¬A
        AperB[i] = CalculateAnd(Abit[i], Bbit[i]);  // A ∩ B
        AobB[i] = (Abit[i] || Bbit[i]);             // A ∪ B
        ArizB[i] = CalculateAnd(Abit[i], !Bbit[i]); // A \ B
        AxorB[i] = (Abit[i] ^ Bbit[i]);             // A ⊕ B
    }

    cout << "\nУніверсум (відсортований): ";
    for (int i = 0; i < n; i++) cout << U[i] << " ";
    cout << "\n";

    cout << "Бітовий рядок A: ";
    for (int i = 0; i < n; i++) cout << Abit[i];
    cout << "\n";

    cout << "Бітовий рядок B: ";
    for (int i = 0; i < n; i++) cout << Bbit[i];
    cout << "\n";

    cout << "not A: ";
    for (int i = 0; i < n; i++) cout << notA[i];
    cout << "\n";

    cout << "A ∩ B: ";
    for (int i = 0; i < n; i++) cout << AperB[i];
    cout << "\n";

    cout << "A ∪ B: ";
    for (int i = 0; i < n; i++) cout << AobB[i];
    cout << "\n";

    cout << "A \\ B: ";
    for (int i = 0; i < n; i++) cout << ArizB[i];
    cout << "\n";

    cout << "A ⊕ B: ";
    for (int i = 0; i < n; i++) cout << AxorB[i];
    cout << "\n";

    return 0;
}

int CalculateAnd(int first, int second) {
    return first && second;
}