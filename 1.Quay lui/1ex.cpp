#include <iostream>
#include <vector>
using namespace std;

void Try(int i, int n, vector<int> &config) {
    // Da xac dinh i-1 cau hinh x1 x2 ... x_i-1
    for (int c = 0; c <= 1; c++) {
        config.push_back(c);
        if (i == n) {
            for (int j = 0; j < config.size(); j++) {
                cout << config[j] << " ";
            }
            cout << endl;
            config.pop_back();
        } else {
            Try(i + 1, n, config);
        }
    }
    config.pop_back();
}

int main() {
    vector<int> config;
    int n = 4;
    Try(1, n, config);
}