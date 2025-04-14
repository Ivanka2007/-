// Lab_7_1.cpp
// < Чичерська Іванна Михайлівна >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 37
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low,
const int High);
void Print(int** a, const int rowCount, const int colCount);
int FindCount(int** a, const int rowCount, const int colCount);
int FindSum(int** a, const int rowCount, const int colCount);
void ChangeEllements(int** a, const int rowCount, const int colCount);

void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);

int main()
{
    srand((unsigned)time(NULL));

    int Low = 4;
    int High = 45;

    int rowCount = 9;
    int colCount = 7;

    int **a = new int*[rowCount];

    for (int i=0; i<rowCount; i++)
        a[i] = new int[colCount];
    
    Create(a, rowCount, colCount, Low, High);

    cout << "Generated array:" << endl;
    Print(a, rowCount, colCount);

    cout << endl;

    cout << "Sorted array:" << endl;
    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    cout << "Count = " << FindCount(a, rowCount, colCount) <<endl;
    cout << "Sum = " << FindSum(a, rowCount, colCount) <<endl;

    cout << "Changer array:" << endl;
    ChangeEllements(a, rowCount, colCount);

    Print(a, rowCount, colCount);

    for (int i=0; i<rowCount; i++)
        delete [] a[i];
    delete [] a;

    return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
const int High)
{
    for (int i=0; i<rowCount; i++)
        for (int j=0; j<colCount; j++)
            a[i][j] = Low + rand() % (High-Low+1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i=0; i<rowCount; i++)
    {
        for (int j=0; j<colCount; j++)
            cout << setw(3) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindCount(int** a, const int rowCount, const int colCount){
    int count = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j=0; j < colCount; j++)
            if (a[i][j] % 2 == 0 && ! (i % 2 != 0 || j % 2 != 0))
               count++;
    return count;
}
int FindSum(int** a, const int rowCount, const int colCount){
    int sum = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j=0; j < colCount; j++)
            if (a[i][j] % 2 == 0 && ! (i % 2 != 0 || j % 2 != 0))
               sum += a[i][j];
    return sum;
}
void ChangeEllements(int** a, const int rowCount, const int colCount){
    for (int i = 0; i < rowCount; i++)
        for (int j=0; j < colCount; j++)
            if (a[i][j] % 2 == 0 && ! (i % 2 != 0 || j % 2 != 0))
               a[i][j] = 0;
}
void Sort(int** a, const int rowCount, const int colCount)
{
    for (int i0=0; i0<rowCount-1; i0++)
        for (int i1=0; i1<rowCount-i0-1; i1++)

            if ( a[i1][0] < a[i1+1][0] )
            {
                Change(a, i1, i1 + 1, colCount);
            }
            else if (a[i1][0] == a[i1 + 1][0])
            {
                if (a[i1][1] > a[i1 + 1][1])
                {
                    Change(a, i1, i1 + 1, colCount);
                }
                else if (a[i1][1] == a[i1 + 1][1])
                {
                    if (a[i1][2] < a[i1 + 1][2])
                    {
                        Change(a, i1, i1 + 1, colCount);
                    }
                }
            }
}
void Change(int** a, const int row1, const int row2, const int colCount)
{
    int tmp;
    for (int j=0; j < colCount; j++)
    {
        tmp = a[row1][j];
        a[row1][j] = a[row2][j];
        a[row2][j] = tmp;
    }
}