#include <iostream>
using namespace std;

bool find(int *arr, int start, int end, int x) {
    // Ly luan bai toan ve truong hop co so
    if (start == end) {
        if (x == arr[start])
            return true;
        else
            return false;
    }
    int mid = (start + end) / 2;
    if (arr[mid] == x)
        return true;
    else if (x > arr[mid]) {
        return find(arr, mid + 1, end, x);
    } else
        return find(arr, start, mid - 1, x);
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int arr[n];
    int x;
    cout << "Input array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Input x: ";
    cin >> x;
    if (find(arr, 0, n - 1, x))
        cout << "exist";
    else
        cout << "does not exist";
}