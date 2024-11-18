#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

template <typename T>
void Create1(T* mas, const int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = (T)(rand() % 6);
	}
}

void Create2(int* mas, const int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 6;
	}
}

template <typename T>
void Print1(T* mas, const int n)
{
	cout << "a[ ";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "]" << endl;
}

void Print2(int* mas, const int n)
{
	cout << "a[ ";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << "]" << endl;
}

template <typename T>
int Perev1(T* mas, const int n)                      // шаблонна функція
{
	if (n < 2)
		cerr << "in arrays one element" << endl;
	for (int i = 1; i < n && !(mas[i - 1] < mas[i]); i++)
	return i >= n;
}

int Perev2(int* mas, const int n)                   // звичайна функція
{
	if (n < 2)
		cerr << "in arrays one element" << endl;
	for (int i = 1; i < n && !(mas[i - 1] < mas[i]); i++)
	return i >= n;
}

int main()
{
	srand((unsigned)time(NULL));

	const int k = 5;
	int a[k];

	Create1<int>(a, k);
	Create2(a, k);

	Print1<int>(a, k);
	Print2(a, k);

	if (Perev1<int>(a, k) == 1)        // виклик шаблонної функції
		cout << "True" << endl;
	else
		cout << "False" << endl;

	if (Perev2(a, k) == 1)        // виклик звичайної функції
		cout << "True" << endl;
	else
		cout << "False" << endl;
	
	return 0;
}