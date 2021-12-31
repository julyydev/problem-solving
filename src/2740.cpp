// https://www.acmicpc.net/problem/2740
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, num;
    cin >> n >> m;
    vector<vector<int>> vec1(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            vec1[i][j] = num;
        }
    }

    cin >> m >> k;
    vector<vector<int>> vec2(m, vector<int>(k, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> num;
            vec2[i][j] = num;
        }
    }

    vector<vector<int>> res(n, vector<int>(k, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int p = 0; p < m; p++) {
                res[i][j] += vec1[i][p] * vec2[p][j];
            }
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}