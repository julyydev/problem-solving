#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

#define EMPTY 10000

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Blocks {
    int n, m;
    int score;
    vector<vector<int>> blocks;

   public:
    Blocks(int n, int m, vector<vector<int>> blocks)
        : n(n), m(m), score(0), blocks(blocks) {}

   private:
    bool remove_max_block_group() {
        vector<Point> max_block_group;
        int max_rainbow_group_number = 0;
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (blocks[i][j] == 0 || blocks[i][j] == -1 ||
                    blocks[i][j] == EMPTY || is_visited[i][j])
                    continue;
                bfs({i, j}, is_visited, max_block_group,
                    max_rainbow_group_number);
            }
        }

        if (max_block_group.size() < 2) return false;

        for (Point block : max_block_group) blocks[block.x][block.y] = EMPTY;
        score += max_block_group.size() * max_block_group.size();
        return true;
    }

    void bfs(Point start, vector<vector<bool>>& is_visited,
             vector<Point>& max_block_group, int& max_rainbow_group_number) {
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};

        int color = blocks[start.x][start.y];
        vector<Point> block_group;
        block_group.push_back(start);
        vector<Point> rainbow_blocks;

        queue<Point> q;
        q.push(start);
        is_visited[start.x][start.y] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n ||
                    is_visited[next.x][next.y] ||
                    blocks[next.x][next.y] == EMPTY)
                    continue;
                if (blocks[next.x][next.y] != color &&
                    blocks[next.x][next.y] != 0)
                    continue;

                q.push(next);
                is_visited[next.x][next.y] = true;
                block_group.push_back(next);
                if (blocks[next.x][next.y] == 0) rainbow_blocks.push_back(next);
            }
        }

        for (Point rainbow_block : rainbow_blocks)
            is_visited[rainbow_block.x][rainbow_block.y] = false;

        if (block_group.size() > max_block_group.size()) {
            max_block_group = block_group;
            max_rainbow_group_number = rainbow_blocks.size();
        } else if (block_group.size() == max_block_group.size()) {
            if (rainbow_blocks.size() < max_rainbow_group_number) return;
            max_block_group = block_group;
            max_rainbow_group_number = rainbow_blocks.size();
        }

        return;
    }

    void gravity() {
        for (int i = 0; i < n; i++) {
            int next = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (blocks[j][i] == EMPTY) continue;
                if (blocks[j][i] == -1) {
                    next = j - 1;
                    continue;
                }

                if (blocks[next][i] != EMPTY) {
                    next--;
                    continue;
                }
                blocks[next--][i] = blocks[j][i];
                blocks[j][i] = EMPTY;
            }
        }
    }

    void rotate() {
        vector<vector<int>> rotated_blocks(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                rotated_blocks[n - 1 - j][i] = blocks[i][j];
        blocks = rotated_blocks;
    }

   public:
    void auto_play() {
        while (1) {
            if (!remove_max_block_group()) break;
            gravity();
            rotate();
            gravity();
        }
    }

    int get_score() { return score; }
};

int main() {
    FASTIO();
    int N, M;
    cin >> N >> M;
    vector<vector<int>> init_blocks(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> init_blocks[i][j];

    Blocks blocks(N, M, init_blocks);
    blocks.auto_play();
    cout << blocks.get_score() << "\n";

    return 0;
}
