#include <iostream>
#include <time.h>

using namespace std;

void CreateArray(int* c, const int size, const int Low, const int High, int i)
{
		c[i] = Low + rand() % (High - Low + 1);
		if (i < size - 1) 
		{
			CreateArray(c, size, Low, High, i + 1);
		}

}

void PrintArray(int* c, const int size, int i)
{
	if (i == 0)
		cout << "a[" << size << "] = {";
	if (i > 0)
		cout << ", ";
	cout << c[i];
	if (i == (size - 1))
		cout << "}" << endl;

	if (i < size - 1)
		PrintArray(c, size, i + 1);
}

int Sum(int* c, const int i)
{
	int s = 0;

	if ((c[i] % 2 != 0) || (i % 13 != 0)) 
	{
		s = c[i];
	}
	if (i > 0) {
		s += Sum(c, i - 1);
	}

	return s;
}

int Amount(int* c, const int i)
{
	int am = 0;
	
		if ((c[i] % 2 != 0) || (i % 13 != 0))
		{
			am++;
		}

		if (i > 0) {
			am += Amount(c, i - 1);
		}

	return am;
}

void ModifyArray(int* c, const int size, int i)
{

	if (i < size) {
		if ((c[i] % 2 == 0) || (i % 13 == 0)) {
			c[i] = 0;
		}
		ModifyArray(c, size, i + 1);
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
	CreateArray(с, k, Low, High, 0);
	PrintArray(с, k, 0);

	cout << "Sum = " << Sum(с, k - 1) << endl;
	cout << "Amount = " << Amount(с, k - 1) << endl;
	cout << "Modified array:" << endl;

	ModifyArray(с, k, 0);
	PrintArray(с, k, 0);

	return 0;
}
