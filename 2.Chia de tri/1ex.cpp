#include <iostream>
using namespace std;

void merge(int *arr, int start, int mid, int end) {
    int begin1 = start;
    int begin2 = mid + 1;
    int newArr[end - start + 1];
    int index = 0;
    do {
        if (arr[begin1] < arr[begin2]) {
            newArr[index] = arr[begin1];
            begin1++;
            index++;
        } else {
            newArr[index] = arr[begin2];
            begin2++;
            index++;
        }
    } while ((begin1 != (mid + 1)) && (begin2 != (end + 1)));
    if (begin1 == (mid + 1) && begin2 == (end + 1)) {
    } else {
        if (begin1 == (mid + 1)) {
            // Gan phan con lai cua begin2 vao newArr
            for (int i = begin2; i <= end; i++) {
                newArr[index] = arr[i];
                index++;
            }
        }
        if (begin2 == (end + 1)) {
            // Gan phan con lai cua begin1 vao newArr
            for (int i = begin1; i <= mid; i++) {
                newArr[index] = arr[i];
                index++;
            }
        }
    }
    int distance = start;
    for (int i = start; i <= end; i++) {
        arr[i] = newArr[i - distance];
    }
}

void sort(int *arr, int start, int end) {
    if (start == end) return;
    int mid = (start + end) / 2;
    sort(arr, start, mid);
    sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    int arr[n];
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}