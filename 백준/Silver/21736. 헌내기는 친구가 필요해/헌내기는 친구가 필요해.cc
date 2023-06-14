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

class Graph {
    int n, m, count;
    vector<vector<char>> graph;

   public:
    Graph(int n, int m, const vector<vector<char>>& graph)
        : n(n), m(m), count(0), graph(graph) {}

    void bfs(Point start) {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};

        vector<vector<bool>> is_visited(n, vector<bool>(m, false));
        queue<Point> q;
        q.push(start);
        is_visited[start.x][start.y] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m ||
                    is_visited[next.x][next.y] || graph[next.x][next.y] == 'X')
                    continue;

                if (graph[next.x][next.y] == 'P') count++;
                q.push(next);
                is_visited[next.x][next.y] = true;
            }
        }

        return;
    }

    void print_person_number() {
        if (count == 0)
            cout << "TT\n";
        else
            cout << count << "\n";
    }
};

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    vector<vector<char>> init_graph(N, vector<char>(M));
    Point start;

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) {
            init_graph[i][j] = s[j];
            if (init_graph[i][j] == 'I') start = {i, j};
        }
    }

    Graph graph(N, M, init_graph);
    graph.bfs(start);
    graph.print_person_number();

    return 0;
}