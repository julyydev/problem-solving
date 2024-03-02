#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Puzzle {
    string init_hash = "";

   public:
    Puzzle() {}

    void init() {
        char x;
        for (int i = 0; i < 9; i++) {
            cin >> x;
            init_hash += x;
        }
    }

    int solve() {
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};

        queue<pair<string, int>> q;
        unordered_set<string> us;

        q.push({init_hash, 0});
        us.insert(init_hash);
        while (!q.empty()) {
            auto [hash, count] = q.front();
            q.pop();
            if (hash == "123456780") return count;

            int empty_index = hash.find("0");
            Point cur = {empty_index / 3, empty_index % 3};
            for (int i = 0; i < 4; i++) {
                Point next = {cur.x + dx[i], cur.y + dy[i]};
                if (next.x < 0 || next.x >= 3 || next.y < 0 || next.y >= 3)
                    continue;

                int next_index = next.x * 3 + next.y;
                string next_hash = hash;
                next_hash[empty_index] = hash[next_index];
                next_hash[next_index] = hash[empty_index];

                if (us.find(next_hash) != us.end()) continue;
                q.push({next_hash, count + 1});
                us.insert(next_hash);
            }
        }

        return -1;
    }
};

int main() {
    FASTIO();
    Puzzle puzzle;
    puzzle.init();
    cout << puzzle.solve() << "\n";

    return 0;
}
