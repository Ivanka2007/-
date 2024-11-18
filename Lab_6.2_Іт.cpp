#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateArray(int* a, const int n, int Low, int High)
{
	for (int i = 0; i < n; i++) 
	{
		a[i] = Low + rand() % (High - Low + 1);
	}
}

void PrintArray(int* a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << a[i];
	}
	cout << endl;
}

int Sum(int* a, const int n, int m, int S)
{
	for (int i = 0; i < n; i++) 
	{
		if (i % 2 == 1) {
			m++;
			S += a[i];
		}
	}
	return S;
}

int main()
{
	srand((unsigned)time(NULL));

	const int n = 10;
	int a[n];
	int S;
	int Low = 15;
	int High = 85;

	CreateArray(a, n, Low, High);
	S = Sum(a, n, 0, 0);
	PrintArray(a, n);
	cout << "Medium Arifmetic: " << S / n << endl;
}