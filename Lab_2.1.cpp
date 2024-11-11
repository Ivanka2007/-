#include <iostream>
#include <cmath>
using namespace std;

void CoutnZ(double b) {
	double z1, z2;
	z1 = (sqrt(2 * b + 2 * sqrt(pow(b, 2) - 4))) / (sqrt(pow(b, 2) - 4) + b + 2);
	cout << "z1: " << z1 << endl;
	z2 = 1 / (sqrt(b + 2));
	cout << "z2: " << z2 << endl;
}
int main() {
	double b = 0;
	cout << "Enter b: "; cin >> b;
	CoutnZ(b);
}