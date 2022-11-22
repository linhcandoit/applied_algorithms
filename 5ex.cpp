#include <iostream>
#include <vector>
using namespace std;

void printConfig(vector<int> config) {
    for (int i = 0; i < config.size(); i++) {
        cout << config[i] << " ";
    }
    cout << endl;
}

void Try(int k, int m, int n, int &sum, vector<int> &config) {
    for (int i = 1; i <= m - sum - n + k; i++) {
        config.push_back(i);
        sum += i;
        if (k == n - 1) {
            config.push_back(m - sum);
            printConfig(config);
            config.pop_back();
            config.pop_back();
            sum -= i;
        } else {
            Try(k + 1, m, n, sum, config);
        }
    }
    sum -= config[config.size() - 1];
    config.pop_back();
}

int main() {
    int m = 5;
    int n = 3;
    vector<int> config;
    int sum = 0;
    Try(1, m, n, sum, config);
}