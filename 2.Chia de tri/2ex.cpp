#include <iostream>
using namespace std;

int maxThreeNum(int max1, int max2, int max3) {
    int max;
    if (max1 > max2)
        max = max1;
    else
        max = max2;
    if (max < max3) max = max3;
    return max;
}

int findMerge(int* arr, int start, int mid, int end) {
    int maxLeft = arr[mid];
    int maxRight = arr[mid + 1];
    int sumLeft = 0;
    int sumRight = 0;
    for (int i = mid; i >= start; i--) {
        sumLeft += arr[i];
        if (sumLeft > maxLeft) maxLeft = sumLeft;
    }
    for (int i = mid + 1; i <= end; i++) {
        sumRight += arr[i];
        if (sumRight > maxRight) maxRight = sumRight;
    }
    return maxLeft + maxRight;
}

int findMax(int* arr, int start, int end) {
    if (start == end) return arr[start];
    int mid = (start + end) / 2;
    int max1 = findMax(arr, start, mid);
    int max2 = findMax(arr, mid + 1, end);
    int max3 = findMerge(arr, start, mid, end);
    return maxThreeNum(max1, max2, max3);
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;
    cout << "Input array: ";
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = findMax(arr, 0, n - 1);
    cout << max;
}