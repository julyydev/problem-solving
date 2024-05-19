#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int n, m;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

void reflex(int& d) {
    if (d == 0)
        d = 3;
    else if (d == 1)
        d = 2;
    else if (d == 2)
        d = 1;
    else if (d == 3)
        d = 0;
}

int get_hole_number(const Point& p) {
    if (p.y == -1) {
        return p.x + 1;
    } else if (p.x == n) {
        return n + p.y + 1;
    } else if (p.y == m) {
        return n + m + (n - p.x);
    } else {
        return n + m + n + (m - p.y);
    }
}

void shoot_light(Point& p, int& d, vector<vector<int>>& mirror) {
    while (1) {
        p = Point(p.x + dx[d], p.y + dy[d]);
        if (p.x < 0 || p.x >= n || p.y < 0 || p.y >= m) break;
        if (mirror[p.x][p.y] == 1) reflex(d);
    }
}

int main() {
    FASTIO();
    cin >> n >> m;

    vector<vector<int>> mirror(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> mirror[i][j];

    vector<int> hole(2 * (n + m) + 1, 0);
    for (int i = 1; i <= n; i++) {
        int d = 0;
        Point p(i - 1, -1);

        shoot_light(p, d, mirror);
        int h = get_hole_number(p);
        hole[i] = h;
        hole[h] = i;
    }

    for (int i = 1; i <= m; i++) {
        int d = 3;
        Point p(n, i - 1);

        shoot_light(p, d, mirror);
        int h = get_hole_number(p);
        hole[n + i] = h;
        hole[h] = n + i;
    }

    for (int i = 1; i <= 2 * (n + m); i++) cout << hole[i] << ' ';
    cout << '\n';

    return 0;
}