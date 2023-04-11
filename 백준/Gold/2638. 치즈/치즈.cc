#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Block {
    bool is_cheese;
    int count;

   public:
    Block() {}
    Block(bool is_cheese) : is_cheese(is_cheese), count(0) {}
    bool isCheese() { return is_cheese; }
    void melt() { is_cheese = false; }
    void increaseCount() { count++; }
    bool isMelting() { return count >= 2; }
    void initCount() { count = 0; }
};

class Cheeses {
    vector<vector<Block>> cheeses;
    int n, m;
    int rest_cheese;
    int time;

   public:
    Cheeses(const int& n, const int& m, vector<vector<int>> init_cheeses)
        : n(n), m(m), time(0) {
        cheeses.resize(n, vector<Block>(m));
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cheeses[i][j] = {init_cheeses[i][j] == 1};
                if (init_cheeses[i][j] == 1) count++;
            }
        }
        rest_cheese = count;
    }
    void bfs() {
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        queue<Point> q;
        q.push({0, 0});
        isVisited[0][0] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m ||
                    isVisited[next.x][next.y])
                    continue;

                if (cheeses[next.x][next.y].isCheese()) {
                    cheeses[next.x][next.y].increaseCount();
                    continue;
                }

                q.push(next);
                isVisited[next.x][next.y] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (cheeses[i][j].isMelting()) {
                    cheeses[i][j].melt();
                    rest_cheese--;
                }
            }
        }

        time++;
        initAllCheese();
    }
    bool isAllMelted() { return rest_cheese == 0; }
    int getTime() { return time; }
    void initAllCheese() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) cheeses[i][j].initCount();
    }
};

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    vector<vector<int>> init_cheeses(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) cin >> init_cheeses[i][j];

    Cheeses cheeses(N, M, init_cheeses);
    while (1) {
        if (cheeses.isAllMelted()) break;
        cheeses.bfs();
    }
    cout << cheeses.getTime() << "\n";

    return 0;
}