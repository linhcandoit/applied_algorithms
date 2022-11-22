#include <iostream>
#include <vector>
using namespace std;

void Try(int i, int n, bool *mark, vector<int> &config) {
    for (int c = 1; c <= n; c++) {
        if (*(mark + c) == false) {
            *(mark + c) = true;
            config.push_back(c);
            if (i == n) {
                // xuat ra cau hinh thoa man
                for (int j = 0; j < config.size(); j++) {
                    cout << config[j] << " ";
                }
                cout << endl;
                config.pop_back();
                *(mark + c) = false;
            } else {
                Try(i + 1, n, mark, config);
            }
        }
    }
    if (!config.empty()) {
        *(mark + config.back()) = false;
        config.pop_back();
    }
}
int main() {
    int n = 3;
    vector<int> config;
    bool mark[n + 1];
    for (int i = 0; i <= n; i++) {
        mark[i] = false;
    }
    Try(1, n, mark, config);
    // hieu ro hon ve cai nay => Ky thuat lap trinh
}