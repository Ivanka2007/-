#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int i;
    double S;

    cout << "i = "; cin >> i;
    S = 0;
    i = 1;
    //1
    while (i <= 15)
    {
        S += ((sin(10) * i) + (cos(10) / i)) / sqrt(i);
        i++;
    }
    cout << S << endl;
    //2
    S = 0;
    i = 1;
    do {
        S += ((sin(10) * i) + (cos(10) / i)) / sqrt(i);
        i++;
    } while (i <= 15);
    cout << S << endl;
    //3
    S = 0;
    for (i = 1; i <= 15; i++)
    {
        S += ((sin(10) * i) + (cos(10) / i)) / sqrt(i);
    }
    cout << S << endl;
    return 0;
}