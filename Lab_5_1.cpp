#include <iostream>
#include <string>

using namespace std;

void Calculate(string D[]);

int main() {
    string D[12];
    Calculate(D);

    cout << "AxCxA:" << endl;
    cout << endl;
    for (int i = 0; i < 12; i++) {
        cout << D[i] << endl;
    }

    return 0;
}

void Calculate(string D[]) {
    char A[] = { 'a', 'b', 'c' };
    char C[] = { '0', '1' };

    int index = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                D[index] = string(1, A[i]) + C[j] + A[k];
                index++;
            }
        }
    }
}