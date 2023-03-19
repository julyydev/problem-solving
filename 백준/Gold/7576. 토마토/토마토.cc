#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int M, N, tomato_num = 0, max_day = 0;
vector<vector<int>> graph;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct Tomato {
    int x, y, day;
    Tomato(int x, int y, int day) : x(x), y(y), day(day){};
};

int bfs(vector<Tomato> initial_tomato) {
    queue<Tomato> q;
    for (auto it = initial_tomato.begin(); it != initial_tomato.end(); it++) {
        q.push(*it);
    }

    while (!q.empty() && tomato_num) {
        Tomato cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = cur.x + dx[i], nextY = cur.y + dy[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
            if (graph[nextX][nextY] == 0) {
                q.push(Tomato(nextX, nextY, cur.day + 1));
                if (cur.day + 1 > max_day) max_day = cur.day + 1;
                graph[nextX][nextY] = 1;
                tomato_num--;
            }
        }
    }

    if (tomato_num == 0)
        return max_day;
    else
        return -1;
}

int main() {
    cin >> M >> N;
    graph.resize(N, vector<int>(M));

    vector<Tomato> initial_tomato;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0) tomato_num++;
            if (graph[i][j] == 1) initial_tomato.push_back(Tomato(i, j, 0));
        }
    }

    cout << bfs(initial_tomato) << "\n";

    return 0;
}