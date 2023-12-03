#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct Data {
    int value;
    Point point;
    Data(int value, Point point) : value(value), point(point) {}

    bool operator<(const Data& d) const { return value < d.value; }
};

int main() {
    FASTIO();
    int n;
    cin >> n;

    priority_queue<Data> pq;
    vector<vector<int>> bamboo(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bamboo[i][j];
            pq.push({bamboo[i][j], {i, j}});
        }
    }

    int max_count = 0;
    vector<vector<int>> count(n, vector<int>(n, 0));
    while (!pq.empty()) {
        auto [value, cur] = pq.top();
        pq.pop();

        int temp = 0;
        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n ||
                value == bamboo[next.x][next.y])
                continue;

            temp = max(temp, count[next.x][next.y]);
        }
        count[cur.x][cur.y] = temp + 1;
        max_count = max(max_count, temp + 1);
    }

    cout << max_count << "\n";

    return 0;
}
