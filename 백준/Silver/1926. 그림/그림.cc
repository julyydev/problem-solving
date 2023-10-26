#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Graph {
    int n, m;
    vector<vector<int>> graph;
    int num = 0;
    int max_area = 0;

   public:
    Graph() {}

    void init() {
        cin >> n >> m;
        graph.resize(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cin >> graph[i][j];
    }

    void bfs() {
        vector<vector<bool>> is_visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == 0 || is_visited[i][j]) continue;

                num++;
                queue<Point> q;

                q.push({i, j});
                is_visited[i][j] = true;

                int area = 1;
                while (!q.empty()) {
                    Point cur = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        Point next(cur.x + dx[i], cur.y + dy[i]);
                        if (next.x < 0 || next.x >= n || next.y < 0 ||
                            next.y >= m || graph[next.x][next.y] == 0 ||
                            is_visited[next.x][next.y])
                            continue;

                        q.push(next);
                        is_visited[next.x][next.y] = true;
                        area++;
                    }
                }

                max_area = max(max_area, area);
            }
        }
    }

    int get_num() { return num; }

    int get_max_area() { return max_area; }
};

int main() {
    FASTIO();
    Graph graph;
    graph.init();
    graph.bfs();
    cout << graph.get_num() << "\n";
    cout << graph.get_max_area() << "\n";

    return 0;
}