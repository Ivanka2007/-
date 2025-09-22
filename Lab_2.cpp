#include <iostream>
using namespace std;

int CalculateImp(int a, int b);
int CalculateFormula(int p, int q, int r);

int main() {
    cout << "p q r  | (p->q) ^ (p->r)\n";
    cout << "-------------------------\n";

    for (int p = 0; p <= 1; p++) {
        for (int q = 0; q <= 1; q++) {
            for (int r = 0; r <= 1; r++) {
                int f = CalculateFormula(p, q, r);

                cout << " " << p << " " << q << " " << r
                     << " |     " << f << "\n";
            }
        }
    }

    cout << "\n=== Перевірка для власних значень ===\n";
    int p, q, r;
    cout << "Enter p (0/1): "; cin >> p;
    cout << "Enter q (0/1): "; cin >> q;
    cout << "Enter r (0/1): "; cin >> r;

    int formula = CalculateFormula(p, q, r);

    cout << "\np q r | (p->q) ^ (p->r)\n";
    cout << "-------------------------\n";
    cout << p << " " << q << " " << r
         << " |     " << formula << "\n";

    return 0;
}

// імплікація (p → q) = (!p) ∨ q
int CalculateImp(int a, int b) {
    return (!a) || b;
}

// формула (p → q) ^ (p → r)
int CalculateFormula(int p, int q, int r) {
    int imp_pq = CalculateImp(p, q);
    int imp_pr = CalculateImp(p, r);
    return imp_pq ^ imp_pr;  // XOR
}