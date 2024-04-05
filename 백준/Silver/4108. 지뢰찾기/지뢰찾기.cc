#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    FASTIO();
    int r, c;
    while (1) {
        cin >> r >> c;
        if (r == 0 && c == 0) break;

        vector<vector<char>> map(r, vector<char>(c));
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) cin >> map[i][j];

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (map[i][j] == '*') continue;

                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= r || nj < 0 || nj >= c ||
                        map[ni][nj] != '*')
                        continue;
                    count++;
                }
                map[i][j] = '0' + count;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << map[i][j];
            cout << "\n";
        }
    }

    return 0;
}