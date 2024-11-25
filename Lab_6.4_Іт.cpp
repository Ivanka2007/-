#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

void CreateRandomArray(double* arr, int n, double start, double end) {
    for (int i = 0; i < n; i++) {
        arr[i] = start + (rand() / (RAND_MAX / (end - start)));
    }
}

void PrintArrayAsRow(const double* arr, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i];
        if (i < n - 1) {
            cout << ", "; 
        }
    }
    cout << " ]" << endl;
}

int FindC(const double* arr, int n, double C) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > C) {
            count++;
        }
    }
    return count;
}

double MaxAbs(const double* arr, int n) {
    int maxAbs = 0, maxAbsIndex = 0;
    int mtpr = 1;

    for (int i = 0; i < n; i++) {
        if (abs(arr[i]) > maxAbs) {
            maxAbs = abs(arr[i]);
            maxAbsIndex = i;
        }
    }
    if (maxAbsIndex != n) {
        for (int j = maxAbsIndex + 1; j < n; j++) {
            mtpr *= arr[j];
        }
    }

    return mtpr;
}


void TransformArray(double* arr, int n) {
    double* negatives = new double[n];
    double* positives = new double[n];

    int negCount = 0, posCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negatives[negCount++] = arr[i];
        }
        else {
            positives[posCount++] = arr[i];
        }
    }

    int index = 0;
    for (int i = 0; i < negCount; i++) {
        arr[index++] = negatives[i];
    }

    for (int i = 0; i < posCount; i++) {
        arr[index++] = positives[i];
    }

    delete[] negatives;
    delete[] positives;
    }

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "Enter size: ";
    cin >> n;
    double* arr = new double[n];
    double C = 0.0;
    cout << "Enter C: ";
    cin >> C;

    cout << "Create Array" << endl;
    CreateRandomArray(arr, n, -10.0, 10.0);

    cout << "Original array:" << endl;
    PrintArrayAsRow(arr, n);

    int c = FindC(arr, n, C);
    cout << "C < = " << c << endl;

    double product = MaxAbs(arr, n);
    cout << "Max abs = " << fixed << setprecision(2) << product << endl;

    cout << "Transformed array:" << endl;
    TransformArray(arr, n);
    PrintArrayAsRow(arr, n);

    delete[] arr;
    return 0;
}