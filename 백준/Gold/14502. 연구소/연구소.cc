#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

int N, M;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int bfs(vector<vector<int>>& map, const vector<Point>& virus_points,
        int& max_size, int size) {
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    queue<Point> q;
    for (Point p : virus_points) {
        q.push(p);
        isVisited[p.x][p.y] = true;
    }

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
                continue;

            if (!isVisited[next.x][next.y] && map[next.x][next.y] == 0) {
                q.push(next);
                isVisited[next.x][next.y] = true;
                size--;
                if (size <= max_size) return 0;
            }
        }
    }

    return size;
}

int main() {
    FASTIO();
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));
    vector<Point> empty_points;
    vector<Point> virus_points;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) empty_points.push_back({i, j});
            if (map[i][j] == 2) virus_points.push_back({i, j});
        }
    }

    int max_size = 0, size = 0;
    for (int i = 0; i < empty_points.size() - 2; i++) {
        for (int j = i + 1; j < empty_points.size() - 1; j++) {
            for (int k = j + 1; k < empty_points.size(); k++) {
                vector<vector<int>> temp = map;
                temp[empty_points[i].x][empty_points[i].y] = 1;
                temp[empty_points[j].x][empty_points[j].y] = 1;
                temp[empty_points[k].x][empty_points[k].y] = 1;
                size =
                    bfs(temp, virus_points, max_size, empty_points.size() - 3);
                if (size > max_size) max_size = size;
            }
        }
    }
    cout << max_size << "\n";

    return 0;
}