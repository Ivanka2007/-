#include <iostream>
#include <cmath>
using namespace std;

class Vector {
private:
    double x;
    double y;
public:
    Vector() : x(0), y(0) {}
    Vector(double a, double b) : x(a), y(b) {}

    double GetX() const { return x; }
    double GetY() const { return y; }
    void SetX(double value) { x = value; }
    void SetY(double value) { y = value; }

    bool Init(double a, double b) {
        x = a;
        y = b;
        return true;
    }

    void Read() {
        cout << "Введіть x = ";
        cin >> x;
        cout << "Введіть y = ";
        cin >> y;
    }

    void Display() const {
        cout << "(" << x << "; " << y << ")" << endl;
    }

    double Length() const {
        return sqrt(x * x + y * y);
    }

    double DotProduct(const Vector& v) const {
        return x * v.x + y * v.y;
    }

    Vector Add(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }

    Vector Subtract(const Vector& v) const {
        return Vector(x - v.x, y - v.y);
    }
};

Vector makeVector(double a, double b) {
    Vector v;
    v.Init(a, b);
    return v;
}

int main() {
    Vector v1, v2;
    cout << "Введіть координати першого вектора:\n";
    v1.Read();
    cout << "Введіть координати другого вектора:\n";
    v2.Read();

    cout << "Перший вектор: "; v1.Display();
    cout << "Другий вектор: "; v2.Display();

    cout << "Довжина першого вектора: " << v1.Length() << endl;
    cout << "Довжина другого вектора: " << v2.Length() << endl;
    cout << "Скалярний добуток: " << v1.DotProduct(v2) << endl;

    Vector sum = v1.Add(v2);
    cout << "Сума векторів: "; sum.Display();

    Vector diff = v1.Subtract(v2);
    cout << "Різниця векторів: "; diff.Display();

    return 0;
}