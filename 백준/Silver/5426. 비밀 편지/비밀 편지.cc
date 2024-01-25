#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    string s;
    while (t--) {
        cin >> s;
        int n = (int)sqrt(s.length());
        vector<vector<char>> matrix(n, vector<char>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) matrix[n - 1 - j][i] = s[n * i + j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cout << matrix[i][j];
        cout << "\n";
    }

    return 0;
}