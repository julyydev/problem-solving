#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

struct Block {
    int id, value;
    Block() {}
    Block(int id, int value) : id(id), value(value) {}
};

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

void bfs(int N, int M, int x, int y, const vector<vector<int>>& map,
         vector<vector<Block>>& blocks, vector<vector<bool>>& isVisited,
         int id) {
    vector<Point> targets;
    int count = 0;
    queue<Point> q;
    q.push({x, y});
    isVisited[x][y] = true;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        targets.push_back(cur);
        count++;

        for (int i = 0; i < 4; i++) {
            Point next(cur.x + dx[i], cur.y + dy[i]);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M ||
                isVisited[next.x][next.y] || map[next.x][next.y] == 1)
                continue;

            q.push(next);
            isVisited[next.x][next.y] = true;
        }
    }

    for (Point p : targets) blocks[p.x][p.y] = {id, count};
    return;
}

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));
    vector<vector<Block>> blocks(N, vector<Block>(M));
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));

    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < M; j++) map[i][j] = s[j] - '0';
    }

    int id = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 1) {
                blocks[i][j] = {0, 0};
            } else {
                if (blocks[i][j].value == 0) {
                    bfs(N, M, i, j, map, blocks, isVisited, id);
                    id++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (blocks[i][j].value == 0) {
                int sum = 1;
                set<int> ids;

                for (int k = 0; k < 4; k++) {
                    Point next(i + dx[k], j + dy[k]);
                    if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
                        continue;

                    if (ids.find(blocks[next.x][next.y].id) == ids.end()) {
                        sum += blocks[next.x][next.y].value;
                        ids.insert(blocks[next.x][next.y].id);
                    }
                }

                cout << sum % 10;
            } else
                cout << "0";
        }
        cout << "\n";
    }

    return 0;
}