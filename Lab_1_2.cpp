#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void Calculate(string a, string b, int n, string x, string y, string z);
char ConjunceteOR(char a, char b);

int main() {
    int n;
    string a, b;

    cout << "Enter n: ";
    cin >> n;

    cout << "Enter a: ";
    cin >> a;

    cout << "Enter b: ";
    cin >> b;

    n = a.length();
    string x = "", y = "", z = "";

    Calculate(a, b, n, x, y, z);
    return 0;
}

void Calculate(string a, string b, int n, string x, string y, string z) {
    for (int i = 0; i < n; i ++) {
        char c;

        c = ConjunceteOR(a[i], b[i]);
        x+= c;

        if (a[i] == '1' && b[i] == '1')
            c = '1';
        else 
            c = '0';
        y += c;

        if (a[i] != b[i])
            c = '1';
        else 
            c = '0';
        z += c;
    }

    cout << "a    = " << a << endl;
    cout << "b    = " << b << endl;
    cout << "OR   = " << x << endl;
    cout << "AND  = " << y << endl;
    cout << "XOR  = " << z << endl;
}

char ConjunceteOR(char a, char b) {
    char c;
    if (a == '1' || b == '1')
        c = '1';
    else
        c = '0';

    return c;
}