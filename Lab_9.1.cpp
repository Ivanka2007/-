#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Specialnist { KN, INF, ME, FI, TN };
string specStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };

struct Student
{
    string prizv;
    int kurs;
    Specialnist spec;
    int fizyka;
    int matematika;
    int informatyka;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
int CountNoThrees(Student* s, const int N);
int CountStudentsAvgLessThan4(Student* s, const int N);
string SubjectWithLowestAverage(Student* s, const int N);

int main()
{
    int N;
    cout << "Введіть кількість студентів: ";
    cin >> N;

    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);

    int countNoThrees = CountNoThrees(s, N);
    int countAvgLessThan4 = CountStudentsAvgLessThan4(s, N);
    string worstSubject = SubjectWithLowestAverage(s, N);

    cout << "Кількість студентів без трійок: " << countNoThrees << endl;
    cout << "Кількість студентів із середнім балом менше 4: " << countAvgLessThan4 << endl;
    cout << "Предмет з найменшим середнім балом: " << worstSubject << endl;

    delete[] s;
    return 0;
}

void Create(Student* s, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " Прізвище: "; getline(cin, s[i].prizv);
        cout << " Курс: "; cin >> s[i].kurs;
        cout << " Спеціальність (0 - КН, 1 - Інф, 2 - МЕ, 3 - ФІ, 4 - ТН): "; cin >> spec;
        s[i].spec = (Specialnist)spec;
        cout << " Оцінка з фізики: "; cin >> s[i].fizyka;
        cout << " Оцінка з математики: "; cin >> s[i].matematika;
        cout << " Оцінка з інформатики: "; cin >> s[i].informatyka;
        cout << endl;
    }
}

void Print(Student* s, const int N)
{
    cout << "====================================================================================================" << endl;
    cout << "| № | Прізвище         | Курс | Спеціальність             | Фізика | Математика | Інформатика |" << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
             << "| " << setw(17) << left << s[i].prizv
             << "| " << setw(4) << right << s[i].kurs << " "
             << "| " << setw(26) << left << specStr[s[i].spec]
             << "| " << setw(6) << right << s[i].fizyka << " "
             << "| " << setw(10) << right << s[i].matematika << " "
             << "| " << setw(11) << right << s[i].informatyka << " |" << endl;
    }
    cout << "====================================================================================================" << endl;
}

int CountNoThrees(Student* s, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].fizyka > 3 && s[i].matematika > 3 && s[i].informatyka > 3)
            count++;
    }
    return count;
}

int CountStudentsAvgLessThan4(Student* s, const int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        double avg = (s[i].fizyka + s[i].matematika + s[i].informatyka) / 3.0;
        if (avg < 4)
            count++;
    }
    return count;
}

string SubjectWithLowestAverage(Student* s, const int N)
{
    double sumFiz = 0, sumMat = 0, sumInf = 0;
    for (int i = 0; i < N; i++)
    {
        sumFiz += s[i].fizyka;
        sumMat += s[i].matematika;
        sumInf += s[i].informatyka;
    }
    double avgFiz = sumFiz / N;
    double avgMat = sumMat / N;
    double avgInf = sumInf / N;

    if (avgFiz <= avgMat && avgFiz <= avgInf)
        return "Фізика";
    else if (avgMat <= avgFiz && avgMat <= avgInf)
        return "Математика";
    else
        return "Інформатика";
}
