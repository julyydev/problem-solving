#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y, d;
    Point() {}
    Point(int x, int y, int d) : x(x), y(y), d(d) {}
};

class Graph {
    int n, m;
    vector<vector<int>> graph;

   public:
    Graph(int n, int m, const vector<vector<int>>& init_graph)
        : n(n), m(m), graph(init_graph) {}

    void bfs(Point start, vector<vector<int>>& result) {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};

        vector<vector<bool>> is_visited(n, vector<bool>(m, false));
        queue<Point> q;
        q.push(start);
        is_visited[start.x][start.y] = true;
        result[start.x][start.y] = start.d;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i], cur.d + 1);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)
                    continue;
                if (is_visited[next.x][next.y] || graph[next.x][next.y] == 0)
                    continue;

                q.push(next);
                is_visited[next.x][next.y] = true;
                result[next.x][next.y] = next.d;
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!is_visited[i][j] && graph[i][j] != 0) result[i][j] = -1;

        return;
    }
};

int main() {
    FASTIO();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> init_graph(n, vector<int>(m));
    Point start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> init_graph[i][j];
            if (init_graph[i][j] == 2) start = {i, j, 0};
        }
    }

    Graph graph(n, m, init_graph);
    vector<vector<int>> result(n, vector<int>(m, 0));
    graph.bfs(start, result);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << result[i][j] << " ";
        cout << "\n";
    }

    return 0;
}