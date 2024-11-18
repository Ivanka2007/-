#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

template <typename T>
void Create1(T* mas, const int n, int i)
{
	mas[i] = (T)(rand() % 6);
	if (i < n - 1)
	   Create1(mas, n, i + 1);
}

void Create2(int* mas, const int n, int i)
{
	mas[i] = (rand() % 6);
	if (i < n - 1)
		Create2(mas, n, i + 1);
}

template <typename T>
void Print1(T* mas, const int n, int i)
{
	cout << mas[i] << " ";
	if (i < n - 1)
		Print1(mas, n, i + 1);
}

void Print2(int* mas, const int n, int i)
{
	cout << mas[i] << " ";
	if (i < n - 1)
	    Print2(mas, n, i + 1);
}

template <typename T>
int Perev1(T* mas, const int n, int i)                    //шаблонна функція             
{
	if (n < 2)
		cerr << "in arrays one element" << endl;
	if (i < n && !(mas[i - 1] < mas[i]))
		return Perev1<T>(mas, n, i + 1);
	else
		return i >= n;
}

int Perev2(int* mas, const int n, int i)            // звичайна функція
{
	if (n < 2)
		cerr << "in arrays one element" << endl;
	if (i < n && !(mas[i - 1] < mas[i]))
		return Perev2(mas, n, i + 1);
	else
		return i >= n;
}

int main()
{
	srand((unsigned)time(NULL));

	const int k = 5;
	int a[k];

	Create1<int>(a, k, 0);
	Create2(a, k, 0);

	cout << "a[ ";
	Print1<int>(a, k, 0);
	cout << "]" << endl;

	cout << "a[ ";
	Print2(a, k, 0);
	cout << "]" << endl;

	if (Perev1<int>(a, k, 1) == 1)  
		cout << "True" << endl;
	else
		cout << "False" << endl;

	if (Perev2(a, k, 1) == 1)
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}