#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

int dx[8] = {0, 1, 2, 2, 1, 0, -1, -1};
int dy[8] = {-1, -1, 0, 1, 2, 2, 1, 0};

int N, M;
vector<vector<int>> graph;

int search_horizontal_line(Point p) {
    int sum = 0;
    for (int i = 0; i < 4; i++) sum += graph[p.x][p.y + i];
    return sum;
}

int search_vertical_line(Point p) {
    int sum = 0;
    for (int i = 0; i < 4; i++) sum += graph[p.x + i][p.y];
    return sum;
}

bool isNear(Point p1, Point p2) {
    if ((abs(p1.x - p2.x) == 1 && p1.y == p2.y) ||
        abs(p1.y - p2.y) == 1 && p1.x == p2.x)
        return true;
    return false;
}

int search_block(Point p) {
    int sum = 0, maxSum = 0;
    vector<int> possibleSum;
    vector<Point> points;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum += graph[p.x + i][p.y + j];
            points.push_back({p.x + i, p.y + j});
        }
    }

    for (int i = 0; i < 8; i++) {
        Point next(p.x + dx[i], p.y + dy[i]);
        if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M) continue;
        for (auto p : points) {
            if (isNear(p, next)) continue;
            if (graph[next.x][next.y] > graph[p.x][p.y])
                possibleSum.push_back(sum - graph[p.x][p.y] +
                                      graph[next.x][next.y]);
        }
    }

    possibleSum.push_back(sum);
    for (auto ps : possibleSum)
        if (ps > maxSum) maxSum = ps;
    return maxSum;
}

int main() {
    FASTIO();
    int max = 0;
    cin >> N >> M;
    graph.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M - 3; j++) {
            int sum = search_horizontal_line({i, j});
            if (sum > max) max = sum;
        }
    }

    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < M; j++) {
            int sum = search_vertical_line({i, j});
            if (sum > max) max = sum;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 1; j++) {
            int sum = search_block({i, j});
            if (sum > max) max = sum;
        }
    }

    cout << max << "\n";

    return 0;
}