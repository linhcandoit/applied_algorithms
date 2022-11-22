// Mở rộng bài toán: x không nhất thiết là số nguyên, * không nhất thiết là phép nhân số nguyên

#include <iostream>
using namespace std;

double pow(double x, int n) {
    if (n == 1) return x;
    if (n % 2 == 0) {
        int value = pow(x, n / 2);
        return value * value;
    } else {
        int value = pow(x, (n - 1) / 2);
        return value * value * x;
    }
}

int main() {
    int n;
    double x;
    cout << "Input x: ";
    cin >> x;
    cout << "Input n: ";
    cin >> n;
    cout << pow(x, n);
}