#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class Vector
{
    T* v;          // динамічний масив
    int size;      // кількість елементів
public:
    Vector(int n);                 // конструктор
    Vector(const Vector& other);   // копіювання
    ~Vector();                     // деструктор

    Vector& operator=(const Vector& other);   // присвоєння

    Vector operator+(const Vector& other);    // додавання векторів
    Vector operator*(T k);                    // множення на число

    T& operator[](int index);      // індексування

    template <class U>
    friend istream& operator>>(istream& is, Vector<U>& x);

    template <class U>
    friend ostream& operator<<(ostream& os, const Vector<U>& x);
};

// ---------------- Конструктор ------------------------
template <class T>
Vector<T>::Vector(int n)
{
    size = n;
    v = new T[size];
    for (int i = 0; i < size; i++)
        v[i] = 0;
}

// ---------------- Конструктор копіювання ----------------
template <class T>
Vector<T>::Vector(const Vector& other)
{
    size = other.size;
    v = new T[size];
    for (int i = 0; i < size; i++)
        v[i] = other.v[i];
}

// ---------------- Деструктор ----------------------------
template <class T>
Vector<T>::~Vector()
{
    delete[] v;
}

// ---------------- Присвоєння ----------------------------
template <class T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
    if (this != &other)
    {
        delete[] v;
        size = other.size;
        v = new T[size];
        for (int i = 0; i < size; i++)
            v[i] = other.v[i];
    }
    return *this;
}

// ---------------- Додавання векторів ---------------------
template <class T>
Vector<T> Vector<T>::operator+(const Vector& other)
{
    if (size != other.size)
        throw runtime_error("Різні розміри векторів!");

    Vector<T> temp(size);
    for (int i = 0; i < size; i++)
        temp.v[i] = v[i] + other.v[i];

    return temp;
}

// ---------------- Множення на число ----------------------
template <class T>
Vector<T> Vector<T>::operator*(T k)
{
    Vector<T> temp(size);
    for (int i = 0; i < size; i++)
        temp.v[i] = v[i] * k;

    return temp;
}

// ---------------- Індексування ---------------------------
template <class T>
T& Vector<T>::operator[](int index)
{
    if (index < 0 || index >= size)
        throw runtime_error("Індекс виходить за межі!");
    return v[index];
}

// ---------------- Ввід ------------------------------
template <class T>
istream& operator>>(istream& is, Vector<T>& x)
{
    for (int i = 0; i < x.size; i++)
    {
        cout << "v[" << i << "] = ";
        is >> x.v[i];
    }
    return is;
}

// ---------------- Вивід ------------------------------
template <class T>
ostream& operator<<(ostream& os, const Vector<T>& x)
{
    for (int i = 0; i < x.size; i++)
        os << x.v[i] << " ";
    os << endl;
    return os;
}

// ==================== MAIN ==============================
int main()
{
    try 
    {
        Vector<int> A(3), B(3);

        cout << "Введіть вектор A:" << endl;
        cin >> A;

        cout << "Введіть вектор B:" << endl;
        cin >> B;

        cout << "A + B = " << (A + B);
        cout << "A * 5 = " << (A * 5);
    }
    catch (exception& e)
    {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}
