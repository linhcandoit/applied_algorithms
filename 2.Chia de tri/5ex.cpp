#include <iostream>
#include <vector>
using namespace std;

void getFibonacci(int n, vector<int> &fibonacci) {
    fibonacci.push_back(0);
    fibonacci.push_back(1);
    fibonacci.push_back(1);
    for (int i = 3; i <= n; i++) {
        int length = fibonacci.size() - 1;
        int value = fibonacci[length - 1] + fibonacci[length];
        fibonacci.push_back(value);
    }
}

char find(int n, int i, vector<int> fibonacci) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (i <= fibonacci[n - 2]) {
        return find(n - 2, i, fibonacci);
    } else
        return find(n - 1, i - fibonacci[n - 2], fibonacci);
}

int main() {
    int n, i;
    cout << "n = ";
    cin >> n;
    cout << "i = ";
    cin >> i;
    vector<int> fibonacci;
    getFibonacci(n, fibonacci);
    cout << find(n, i, fibonacci);
}