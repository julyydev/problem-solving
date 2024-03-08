#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) nums[i][j] = s[j] - '0';
    }

    int max_size = 1;
    for (int l = 2; l <= min(n, m); l++) {
        for (int i = 0; i < n - l + 1; i++) {
            for (int j = 0; j < m - l + 1; j++) {
                if (nums[i][j] == nums[i][j + l - 1] &&
                    nums[i][j] == nums[i + l - 1][j] &&
                    nums[i][j] == nums[i + l - 1][j + l - 1])
                    max_size = max(max_size, l * l);
            }
        }
    }

    cout << max_size << "\n";

    return 0;
}