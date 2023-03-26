#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Position {
    int x, y, dist;
    Position(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    bool operator<(const Position& d) const {
        if (dist == d.dist) {
            if (x == d.x) return y > d.y;
            return x > d.x;
        }
        return dist > d.dist;
    }
};

template <typename T>
class Vector2D {
    vector<vector<T>> vector_2d;

   public:
    Vector2D() {}
    void init(int n, int m, int init_value) {
        vector_2d.assign(n, vector<T>(m, init_value));
    }
    T getValue(int x, int y) { return vector_2d[x][y]; }
    T getValue(Position p) { return vector_2d[p.x][p.y]; }
    void setValue(int x, int y, T value) { vector_2d[x][y] = value; }
    void setValue(Position p, T value) { vector_2d[p.x][p.y] = value; }
};

struct Shark {
    Position position;
    int size;
    int eaten_num;

    Shark() : position({0, 0, 0}), size(2), eaten_num(0) {}
    void eat() {
        eaten_num++;
        if (eaten_num == size) {
            size++, eaten_num = 0;
        }
    }
};

class Fishes {
    vector<int> fish_nums;

   public:
    Fishes() { fish_nums.assign(7, 0); }
    void executePrefixSum() {
        for (int i = 2; i <= 6; i++) fish_nums[i] += fish_nums[i - 1];
    }
    int getFishNum(int shark_size) {
        if (shark_size >= 7) return fish_nums[6];
        return fish_nums[shark_size - 1];
    }
    void increaseFishNum(int i) { fish_nums[i]++; }
    void decreaseFishNum(int fish_size) {
        for (int i = fish_size; i <= 6; i++) fish_nums[i]--;
    }
};

int N;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int bfs(Shark& shark, Fishes& fishes, Vector2D<int>& map,
        Vector2D<bool>& isVisited) {
    isVisited.init(N, N, false);
    priority_queue<Position> pq;
    pq.push({shark.position});
    isVisited.setValue(shark.position, true);

    while (!pq.empty()) {
        Position cur = pq.top();
        pq.pop();
        int fish_size = map.getValue(cur);
        if (fish_size > 0 && fish_size < shark.size) {
            shark.eat();
            shark.position = {cur.x, cur.y, 0};
            map.setValue(cur, 0);
            fishes.decreaseFishNum(fish_size);
            return cur.dist;
        }

        for (int i = 0; i < 4; i++) {
            Position next(cur.x + dx[i], cur.y + dy[i], cur.dist + 1);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N ||
                isVisited.getValue(next))
                continue;
            if (map.getValue(next) > shark.size)
                continue;
            else {
                pq.push({next});
                isVisited.setValue(next, true);
            }
        }
    }

    return 0;
}

int main() {
    FASTIO();
    cin >> N;
    Vector2D<int> map;
    Vector2D<bool> isVisited;
    map.init(N, N, 0);
    Shark shark;
    Fishes fishes;

    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            map.setValue(i, j, x);
            if (x == 9) {
                map.setValue(i, j, 0);
                shark.position = {i, j, 0};
            } else if (x >= 1 || x <= 6)
                fishes.increaseFishNum(x);
        }
    }
    fishes.executePrefixSum();

    int total_time = 0, time;
    while (fishes.getFishNum(shark.size)) {
        time = bfs(shark, fishes, map, isVisited);
        if (time == 0) break;
        total_time += time;
    }
    cout << total_time << "\n";

    return 0;
}