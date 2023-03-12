#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int map[50][50];
bool isVisited[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int M, N;

class P {
   public:
    int x;
    int y;

    P(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

void init() {
    memset(map, 0, sizeof(map));
    memset(isVisited, false, sizeof(isVisited));
    return;
}

void bfs(P start) {
    queue<P> q;
    q.push(P(start.x, start.y));
    isVisited[start.x][start.y] = true;

    while (!q.empty()) {
        P cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            P next = P(cur.x + dx[i], cur.y + dy[i]);
            if (next.x >= 0 && next.x < M && next.y >= 0 && next.y < N &&
                map[next.x][next.y] == 1 && !isVisited[next.x][next.y]) {
                q.push(P(next.x, next.y));
                isVisited[next.x][next.y] = true;
            }
        }
    }
    return;
}

int main() {
    int T, K, X, Y;
    cin >> T;

    for (int i = 0; i < T; i++) {
        init();
        int count = 0;
        cin >> M >> N >> K;
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            map[X][Y] = 1;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && !isVisited[i][j]) {
                    bfs(P(i, j));
                    count++;
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}