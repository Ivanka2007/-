#include <iostream>
#include <time.h>

using namespace std;

void CreateArray(int* с, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++) 
	{
		с[i] = Low + rand() % (High - Low + 1);
	}
}

void PrintArray(int* с, const int size)
{
	cout << "c[" << size << "] = {";
	for (int i = 0; i < size; i++) 
	{
		cout << (i > 0 ? ", " : "") << с[i];
	}
	cout << "}" << endl;
}

int Sum(int* с, const int n)
{
	int s = 0;

	for (int i = 0; i < n; i++)
	{
		if ((с[i] % 2 != 0) || (i % 13 != 0))
		{
			s += с[i];
		}
	}

	return s;
}

int Amount(int* с, const int n)
{
	int am = 0;

	for (int i = 0; i < n; i++) 
	{
		if ((с[i] % 2 != 0) || (i % 13 != 0))
		{
			am++;
		}
	}

	return am;
}

void ModifyArray(int* с, const int size)
{
	for (int i = 0; i < size; i++) 
	{
		if (с[i] % 2 == 0)
		{
			с[i] = 0;
		}
		else if (i % 13 == 0)
		{
			с[i] = 0;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));

	const int k = 21;

	int с[k];

	int Low = 15;
	int High = 85;
	cout << "Array :" << endl;
	CreateArray(с, k, Low, High);
	PrintArray(с, k);

	cout << "Sum = " << Sum(с, k) << endl;
	cout << "Amount = " << Amount(с, k) << endl;
	cout << "Modified array:" << endl;

	ModifyArray(с, k);
	PrintArray(с, k);

	return 0;
}