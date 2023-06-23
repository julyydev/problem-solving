#include <iostream>
#include <queue>
#include <set>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator<(const Point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

class Building {
    int h, w;
    vector<vector<char>> map;
    vector<bool> key;
    set<Point> entrances;
    int stolen_documents_number;

   public:
    Building(int h, int w, vector<vector<char>> init_map, string init_key)
        : h(h), w(w), map(init_map), stolen_documents_number(0) {
        key.assign(26, false);
        if (init_key == "0") return;
        for (auto k : init_key) key[k - 'a'] = true;
    }

    void explore() {
        for (int i = 0; i < w; i++) {
            if (map[0][i] == '*') continue;
            entrances.insert({0, i});
        }
        for (int i = 1; i < h - 1; i++) {
            if (map[i][0] == '*') continue;
            entrances.insert({i, 0});
        }
        for (int i = 1; i < h - 1; i++) {
            if (map[i][w - 1] == '*') continue;
            entrances.insert({i, w - 1});
        }
        for (int i = 0; i < w; i++) {
            if (map[h - 1][i] == '*') continue;
            entrances.insert({h - 1, i});
        }

        bool check = false;
        while (!check) {
            check = true;

            for (auto entrance : entrances) {
                check = bfs(entrance);
                if (!check) break;
            }
        }
    }

    bool bfs(Point start) {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};

        vector<vector<bool>> is_visited(h, vector<bool>(w, false));
        queue<Point> q;
        if (map[start.x][start.y] >= 'A' && map[start.x][start.y] <= 'Z') {
            if (key[map[start.x][start.y] - 'A'])
                map[start.x][start.y] = '.';
            else
                return true;
        } else if (map[start.x][start.y] >= 'a' &&
                   map[start.x][start.y] <= 'z') {
            if (!key[map[start.x][start.y] - 'a']) {
                key[map[start.x][start.y] - 'a'] = true;
                map[start.x][start.y] = '.';
                return false;
            } else
                map[start.x][start.y] = '.';
        } else if (map[start.x][start.y] == '$') {
            map[start.x][start.y] = '.';
            stolen_documents_number++;
        }

        q.push(start);
        is_visited[start.x][start.y] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= h || next.y < 0 || next.y >= w ||
                    is_visited[next.x][next.y] || map[next.x][next.y] == '*')
                    continue;

                if (map[next.x][next.y] >= 'A' && map[next.x][next.y] <= 'Z') {
                    if (!key[map[next.x][next.y] - 'A']) continue;
                    map[next.x][next.y] = '.';
                } else if (map[next.x][next.y] >= 'a' &&
                           map[next.x][next.y] <= 'z') {
                    if (!key[map[next.x][next.y] - 'a']) {
                        key[map[next.x][next.y] - 'a'] = true;
                        map[next.x][next.y] = '.';
                        return false;
                    } else
                        map[next.x][next.y] = '.';
                } else if (map[next.x][next.y] == '$') {
                    map[next.x][next.y] = '.';
                    stolen_documents_number++;
                }

                q.push(next);
                is_visited[next.x][next.y] = true;
            }
        }

        return true;
    }

    int get_stolen_documents_num() { return stolen_documents_number; }
};

int main() {
    FASTIO();
    int T, h, w;
    string s;
    cin >> T;

    while (T--) {
        cin >> h >> w;
        vector<vector<char>> init_map(h, vector<char>(w));
        for (int i = 0; i < h; i++) {
            cin >> s;
            for (int j = 0; j < w; j++) init_map[i][j] = s[j];
        }
        cin >> s;

        Building building(h, w, init_map, s);
        building.explore();
        cout << building.get_stolen_documents_num() << "\n";
    }

    return 0;
};