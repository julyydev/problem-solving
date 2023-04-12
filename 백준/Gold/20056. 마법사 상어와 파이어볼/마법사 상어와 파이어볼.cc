#include <iostream>
#include <map>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

class Fireball {
    int m, d, s;
    Point point;

   public:
    Fireball(Point point, int m, int d, int s)
        : point(point), m(m), d(d), s(s) {}
    int getMass() { return m; }
    int getSpeed() { return s; }
    int getDirection() { return d; }
    Point getPoint() { return point; }
    void move(int map_size) {
        point = {((point.x + dx[d] * s) % map_size + map_size) % map_size,
                 ((point.y + dy[d] * s) % map_size + map_size) % map_size};
    }
};

class Wizzard {
    map<int, Fireball> fireballs;
    int map_size;
    int id;

   public:
    Wizzard(int N) : map_size(N), id(0) {}

   private:
    void moveFireballs() {
        for (auto& fireball : fireballs) {
            fireball.second.move(map_size);
        }
    }
    void mergeFireballs() {
        vector<vector<vector<int>>> map(map_size,
                                        vector<vector<int>>(map_size));

        for (auto& fireball : fireballs) {
            map[fireball.second.getPoint().x][fireball.second.getPoint().y]
                .push_back(fireball.first);
        }

        for (int i = 0; i < map_size; i++) {
            for (int j = 0; j < map_size; j++) {
                if (map[i][j].size() <= 1) continue;

                int next_m = 0, next_s = 0;
                bool all_odd = true, all_even = true;
                for (int i : map[i][j]) {
                    next_m += fireballs.at(i).getMass();
                    next_s += fireballs.at(i).getSpeed();
                    if (fireballs.at(i).getDirection() % 2 == 0)
                        all_odd = false;
                    else
                        all_even = false;
                }
                next_m /= 5, next_s /= map[i][j].size();

                if (next_m != 0) {
                    for (int k = 0; k < 4; k++) {
                        if (all_odd || all_even)
                            insertFiraball(i, j, next_m, next_s, 2 * k);
                        else
                            insertFiraball(i, j, next_m, next_s, 2 * k + 1);
                    }
                }
                for (int i : map[i][j]) fireballs.erase(i);
            }
        }
    }

   public:
    void insertFiraball(int r, int c, int m, int s, int d) {
        fireballs.insert({id++, Fireball({r, c}, m, d, s)});
    }
    void moveAndMergeAllFireball() {
        moveFireballs();
        mergeFireballs();
    }
    int getSumOfFireballMass() {
        int sum = 0;
        for (auto& fireball : fireballs) sum += fireball.second.getMass();
        return sum;
    }
};

int main() {
    FASTIO();
    int N, M, K, r, c, m, s, d;
    cin >> N >> M >> K;

    Wizzard wizzard(N);
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> m >> s >> d;
        wizzard.insertFiraball(r - 1, c - 1, m, s, d);
    }

    while (K--) wizzard.moveAndMergeAllFireball();
    cout << wizzard.getSumOfFireballMass() << "\n";

    return 0;
}