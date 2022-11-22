#include <iostream>
#include <vector>
using namespace std;

void test(int i) {
    if (i == 1)
        return;
    else
        cout << "success";
}

int main() {
    int i = 2;
    test(i);
}