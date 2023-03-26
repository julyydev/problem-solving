#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator<(const Point& p) const {
        if (x == p.x) return y < p.y;
        return x < p.x;
    }
};

struct Data {
    Point point;
    int time;
    Data(Point point, int time) : point(point), time(time) {}
};

class Shark {
    Point point;
    int size;
    int eaten_num;
    void grow() { size++, eaten_num = 0; }

   public:
    Shark() : point({0, 0}), size(2), eaten_num(0) {}
    Shark(Point point) : point(point), size(2), eaten_num(0) {}
    Point getPoint() { return point; }
    void setPoint(Point next) { point = Point(next); }
    int getSize() { return size; }
    void eat() {
        eaten_num++;
        if (eaten_num == size) grow();
    }
};

class Fishes {
    vector<int> fish_nums;

   public:
    Fishes() { fish_nums.resize(7, 0); }
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
vector<vector<int>> map;
vector<vector<bool>> isVisited;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int bfs(Shark& shark, Fishes& fishes) {
    isVisited.clear();
    isVisited.resize(N, vector<bool>(N, false));
    vector<Point> possiblePoints;
    int min_time = INT32_MAX;
    queue<Data> q;
    q.push({shark.getPoint(), 0});
    isVisited[shark.getPoint().x][shark.getPoint().y] = true;

    while (!q.empty()) {
        Data cur = q.front();
        q.pop();
        if (cur.time >= min_time) break;

        for (int i = 0; i < 4; i++) {
            Point next(cur.point.x + dx[i], cur.point.y + dy[i]);
            if (next.x < 0 || next.x >= N || next.y < 0 || next.y >= N)
                continue;
            if (isVisited[next.x][next.y]) continue;

            int fish_size = map[next.x][next.y];
            if (fish_size > 0 && fish_size < shark.getSize()) {
                possiblePoints.push_back(next);
                if (min_time == INT32_MAX) min_time = cur.time + 1;
            } else if (fish_size == 0 || fish_size == shark.getSize()) {
                q.push({next, cur.time + 1});
                isVisited[next.x][next.y] = true;
            }
        }
    }

    if (possiblePoints.size() == 0) return min_time;

    sort(possiblePoints.begin(), possiblePoints.end());
    shark.eat();
    shark.setPoint(possiblePoints[0]);
    map[possiblePoints[0].x][possiblePoints[0].y] = 0;
    fishes.decreaseFishNum(map[possiblePoints[0].x][possiblePoints[0].y]);
    return min_time;
}

int main() {
    FASTIO();
    cin >> N;
    map.resize(N, vector<int>(N));
    Shark shark;
    Fishes fishes;

    int x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            map[i][j] = x;
            if (x == 9) {
                map[i][j] = 0;
                shark = Shark({i, j});
            } else if (x >= 1 || x <= 6)
                fishes.increaseFishNum(x);
        }
    }
    fishes.executePrefixSum();

    int total_time = 0, time;
    while (fishes.getFishNum(shark.getSize())) {
        time = bfs(shark, fishes);
        if (time == INT32_MAX) break;
        total_time += time;
    }
    cout << total_time << "\n";

    return 0;
}