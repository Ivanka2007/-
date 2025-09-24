#include <iostream>
#include <cmath> 
using namespace std;

class FloatPower
{
private:
    double first; 
    double second;  
public:
    double GetFirst() const { return first; }
    double GetSecond() const { return second; }

    void SetFirst(double value) {
        if (value != 0)
            first = value;
        else {
            cout << "Error: first cannot be zero! Assigned 1 by default.\n";
            first = 1;
        }
    }

    void SetSecond(double value) {
        second = value;
    }

    bool Init(double x, double y) {
        if (x == 0) {
            first = 1;
            second = 0;
            return false;
        }
        first = x;
        second = y;
        return true;
    }

    void Display() const {
        cout << "first = " << first << ", second = " << second << endl;
    }

    void Read() {
        double x, y;
        cout << "first (≠0) = ";
            cin >> x;
        cout << "second = ";
        cin >> y;
        Init(x, y);
    }

    double power() const {
        return pow(first, second);
    }
};

FloatPower makeFloatPower(double x, double y)
{
    FloatPower fp;
    if (!fp.Init(x, y))
        cout << "wrong argument to Init (first = 0)" << endl;
    return fp;
}

int main()
{
    FloatPower k;
    k.Read();
    k.Display();
    cout << "Result of power: " << k.power() << endl;

    double a, b;
    cout << "\nEnter values for another object:\n";
    cout << "first = ";
    cin >> a;
    cout << "second = ";
    cin >> b;

    FloatPower i = makeFloatPower(a, b);
    i.Display();
    cout << "Result of power: " << i.power() << endl;

    return 0;
}
