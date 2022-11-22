#include <iostream>
#include <vector>
using namespace std;

void printConfig(vector<int> &config) {
    for (int i = 1; i < config.size(); i++) {
        cout << config[i] << " ";
    }
    cout << endl;
}

void Try(int k, int n, int m, bool *mark, vector<int> &config) {
    for (int i = config[config.size() - 1] + 1; i <= n; i++) {
        if (mark[i] == false) {
            config.push_back(i);
            mark[i] = true;
            if (k == m) {
                printConfig(config);
                config.pop_back();
                mark[i] = false;
            } else {
                Try(k + 1, n, m, mark, config);
            }
        }
    }
    mark[config[config.size() - 1]] = false;
    config.pop_back();
}

int main() {
    int n = 5;
    int m = 3;
    vector<int> config;
    config.push_back(0);
    bool mark[n + 1];
    for (int i = 0; i <= n; i++) {
        mark[i] = false;
    }

    Try(1, n, m, mark, config);
}