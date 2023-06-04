#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int R, C;

void backtracking(int count, int& max_count, Point cur,
                  vector<bool>& is_checked, const vector<vector<char>>& map) {
    for (int i = 0; i < 4; i++) {
        Point next(cur.x + dx[i], cur.y + dy[i]);
        if (next.x < 0 || next.x >= R || next.y < 0 || next.y >= C) continue;
        if (is_checked[map[next.x][next.y] - 'A']) continue;

        is_checked[map[next.x][next.y] - 'A'] = true;
        backtracking(count + 1, max_count, next, is_checked, map);
        is_checked[map[next.x][next.y] - 'A'] = false;
    }

    if (count > max_count) max_count = count;
    return;
}

int main() {
    FASTIO();
    cin >> R >> C;
    vector<vector<char>> map(R, vector<char>(C));
    string s;

    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) map[i][j] = s[j];
    }

    vector<bool> is_checked(26, false);
    is_checked[map[0][0] - 'A'] = true;
    int max_count = 1;
    backtracking(1, max_count, {0, 0}, is_checked, map);
    cout << max_count << "\n";

    return 0;
}