#include <iostream>
#include <vector>
using namespace std;

void Try(int i, int n, vector<int>& config) {
    if (config[config.size() - 1] == 1) {
        for (int c = 0; c <= 1; c++) {
            config.push_back(c);
            if (i == n) {
                // Xuat ra config thoa man
                for (int j = 1; j < config.size(); j++) {
                    cout << config[j] << " ";
                }
                cout << endl;
                config.pop_back();
            } else {
                Try(i + 1, n, config);
            }
        }
        config.pop_back();
    } else {
        // phan tu x_(i-1) = 0
        config.push_back(1);
        if (i == n) {
            // Xuat ra config thoa man
            for (int j = 1; j < config.size(); j++) {
                cout << config[j] << " ";
            }
            cout << endl;
            config.pop_back();
        } else {
            Try(i + 1, n, config);
        }
        config.pop_back();
    }
}

int main() {
    int n = 2;
    vector<int> config;
    config.push_back(1);
    Try(1, n, config);
}