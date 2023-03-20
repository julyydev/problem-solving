#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

vector<vector<vector<int>>> tomato;
int M, N, H, tomato_num = 0, max_day = 0;

int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

struct Tomato {
    int x, y, z, day;
    Tomato(int x, int y, int z, int day) : x(x), y(y), z(z), day(day){};
};

int bfs(vector<Tomato> initial_tomato) {
    queue<Tomato> q;
    for (auto it = initial_tomato.begin(); it != initial_tomato.end(); it++)
        q.push(*it);

    while (!q.empty() && tomato_num) {
        Tomato cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            Tomato next(cur.x + dx[i], cur.y + dy[i], cur.z + dz[i],
                        cur.day + 1);
            if (next.x < 0 || next.x >= M || next.y < 0 || next.y >= N ||
                next.z < 0 || next.z >= H)
                continue;
            if (tomato[next.z][next.y][next.x] == 0) {
                q.push(next);
                tomato[next.z][next.y][next.x] = 1;
                tomato_num--;
                if (next.day > max_day) max_day = next.day;
            }
        }
    }

    if (tomato_num == 0)
        return max_day;
    else
        return -1;
}

int main() {
    FASTIO();
    cin >> M >> N >> H;
    tomato.resize(H, vector<vector<int>>(N, vector<int>(M)));
    vector<Tomato> initial_tomato;

    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> tomato[h][n][m];
                if (tomato[h][n][m] == 0)
                    tomato_num++;
                else if (tomato[h][n][m] == 1)
                    initial_tomato.push_back({m, n, h, 0});
            }
        }
    }

    cout << bfs(initial_tomato) << "\n";

    return 0;
}