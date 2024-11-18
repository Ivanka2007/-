#include <iostream>

using namespace std;

void CreateArray(int* a, int n, int i) //masive
{
		a[i] = 15 + rand() % 71;
		if (i < n - 1) {
			CreateArray(a, n, i + 1);
		}
}

void Sum(int* a, int n, int &S, int i) //search
{
	if (i % 2 == 1)
	{
		S += a[i];
	}
	if (i < n - 1)
	{
		Sum(a, n, S, i + 1);
	}
}

void PrintArray(int* a, const int n, int S, int i) //output
{
	cout << a[i] << " ";
	if (i < n - 1) {
		PrintArray(a, n, S, i + 1);
	}
	else {
		cout << endl;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int a[n];
	int S = 0, i=0;

	CreateArray(a, n, i);
	Sum(a, n, S, i);
	PrintArray(a, n, S, i);
	cout << "MediumAriphmetic = " << (S / n) << endl;

	return 0;
}