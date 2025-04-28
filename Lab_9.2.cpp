#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialnist { KN, IT, PI, ME, TN };
string specStr[] = { "Комп'ютерні науки", "Інформаційні технології", "Прикладна інформатика", "Математика і економіка", "Трудове навчання" };

struct Student 
{
    string prizv;
    int kurs;
    Specialnist spec;
    int physics;
    int math;
    int informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Sort(Student* s, const int N);
int* IndexSort(Student* s, const int N);
void PrintIndexSorted(Student* s, int* I, const int N);
int BinSearch(Student* s, const int N, const string prizv, const double avg, const int thirdGrade);
double AvgMark(Student s);
int ThirdMark(Student s);

int main() 
{
    int N;
    cout << "Введіть кількість студентів: "; cin >> N;
    cout << endl;
    Student* s = new Student[N];

    Create(s, N);
    Print(s, N);

    cout << "Оберіть дію: \n1 - Фізичне впорядкування\n2 - Індексне впорядкування\n3 - Бінарний пошук\nВаш вибір: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        Sort(s, N);
        Print(s, N);
    }
    else if (choice == 2) {
        int* indexArray = IndexSort(s, N);
        PrintIndexSorted(s, indexArray, N);
        delete[] indexArray;
    }
    else if (choice == 3) {
        string prizv;
        double avg;
        int thirdGrade;
        cout << "Введіть прізвище: "; cin >> prizv;
        cout << "Введіть середній бал: "; cin >> avg;
        cout << "Введіть оцінку з профільного предмету: "; cin >> thirdGrade;

        Sort(s, N);

        int found = BinSearch(s, N, prizv, avg, thirdGrade);
        if (found != -1)
            cout << "Студента знайдено на позиції " << found + 1 << endl;
        else
            cout << "Студента не знайдено" << endl;
    }

    delete[] s;
    return 0;
}

void Create(Student* s, const int N) 
{
    for (int i = 0; i < N; i++) 
    {
        cout << "Студент № " << i + 1 << ":\n";
        cout << " Прізвище: "; cin >> s[i].prizv;
        cout << " Курс: "; cin >> s[i].kurs;
        cout << " Спеціальність [0 - КН], [1 - ІТ], [2 - ПІ], [3 - МЕ], [4 - ТН]: ";
        int spec; cin >> spec;
        s[i].spec = (Specialnist)spec;
        cout << " Оцінки (Фізика, Математика, Інформатика): ";
        cin >> s[i].physics >> s[i].math >> s[i].informatics;
        cout << endl;
    }
}

void Print(Student* s, const int N) 
{
    cout << "==================================================================================================" << endl;
    cout << "| № | Прізвище         | Курс | Спеціальність             | Фізика | Математика | Інформатика |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << "| " << setw(2) << right << i + 1 << " "
             << "| " << setw(17) << left << s[i].prizv
             << "| " << setw(4) << right << s[i].kurs << " "
             << "| " << setw(26) << left << specStr[s[i].spec]
             << "| " << setw(6) << right << s[i].physics << " "
             << "| " << setw(10) << right << s[i].math << " "
             << "| " << setw(11) << right << s[i].informatics << " |" << endl;
    }
    cout << "==================================================================================================" << endl << endl;
}

double AvgMark(Student s) 
{
    return (s.physics + s.math + s.informatics) / 3.0;
}

int ThirdMark(Student s)
{
    return s.informatics;
}

void Sort(Student* s, const int N) 
{
    for (int i = 0; i < N - 1; i++) 
        for (int j = 0; j < N - i - 1; j++) 
            if (ThirdMark(s[j]) < ThirdMark(s[j + 1]) ||
                (ThirdMark(s[j]) == ThirdMark(s[j + 1]) && AvgMark(s[j]) < AvgMark(s[j + 1])) ||
                (ThirdMark(s[j]) == ThirdMark(s[j + 1]) && AvgMark(s[j]) == AvgMark(s[j + 1]) && s[j].prizv > s[j + 1].prizv)) 
            {
                swap(s[j], s[j + 1]);
            }
}

int* IndexSort(Student* s, const int N) 
{
    int* I = new int[N];
    for (int i = 0; i < N; i++) I[i] = i;

    for (int i = 1; i < N; i++) 
    {
        int value = I[i];
        int j = i - 1;
        while (j >= 0 &&
            (ThirdMark(s[I[j]]) < ThirdMark(s[value]) ||
            (ThirdMark(s[I[j]]) == ThirdMark(s[value]) && AvgMark(s[I[j]]) < AvgMark(s[value])) ||
            (ThirdMark(s[I[j]]) == ThirdMark(s[value]) && AvgMark(s[I[j]]) == AvgMark(s[value]) && s[I[j]].prizv > s[value].prizv)))
        {
            I[j + 1] = I[j];
            j--;
        }
        I[j + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* s, int* I, const int N) 
{
    cout << "==================================================================================================" << endl;
    cout << "| № | Прізвище         | Курс | Спеціальність             | Фізика | Математика | Інформатика |" << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++) 
    {
        cout << "| " << setw(2) << right << i + 1 << " "
             << "| " << setw(17) << left << s[I[i]].prizv
             << "| " << setw(4) << right << s[I[i]].kurs << " "
             << "| " << setw(26) << left << specStr[s[I[i]].spec]
             << "| " << setw(6) << right << s[I[i]].physics << " "
             << "| " << setw(10) << right << s[I[i]].math << " "
             << "| " << setw(11) << right << s[I[i]].informatics << " |" << endl;
    }
    cout << "==================================================================================================" << endl << endl;
}

int BinSearch(Student* s, const int N, const string prizv, const double avg, const int thirdGrade) 
{
    int left = 0, right = N - 1;
    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (s[mid].prizv == prizv && fabs(AvgMark(s[mid]) - avg) < 1e-6 && ThirdMark(s[mid]) == thirdGrade)
            return mid;

        if (ThirdMark(s[mid]) < thirdGrade ||
            (ThirdMark(s[mid]) == thirdGrade && AvgMark(s[mid]) < avg) ||
            (ThirdMark(s[mid]) == thirdGrade && fabs(AvgMark(s[mid]) - avg) < 1e-6 && s[mid].prizv < prizv))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}