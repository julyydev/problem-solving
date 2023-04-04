#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};  // ↑, ↖, ←, ↙, ↓, ↘, →, ↗
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};  // ↑, ↖, ←, ↙, ↓, ↘, →, ↗

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

class Fish {
    int number;     // 1~16: 물기, 0: 상어, -1: 죽은 물기
    int direction;  // 0~7
    Point point;

   public:
    Fish(int number, int direction, Point point)
        : number(number), direction(direction), point(point) {}
    bool operator<(const Fish& f) const { return number < f.number; }

    int getNumber() { return number; }
    bool isAlive() { return number != -1; }
    Point getPoint() { return point; }
    void setPoint(Point p) { point.x = p.x, point.y = p.y; }
    int getDirection() { return direction; }
    void setDirection(int value) { direction = value; }
    void turn() { direction = (direction + 1) % 8; }
    void die() { number = -1; }
    void swap(Fish& f) {
        Point temp = point;
        point = f.point;
        f.point = temp;
    }
};

class Shark : public Fish {
    int score = 0;

   public:
    Shark() : Fish(0, 0, {0, 0}) {}
    void eat(Fish& f) {
        score += f.getNumber();
        f.die();
        setPoint(f.getPoint());
        setDirection(f.getDirection());
    }
    int getScore() { return score; }
};

class Sea {
    vector<Fish> fishes;
    Shark shark;

   public:
    Sea(vector<Fish> init_fishes) : fishes(init_fishes) {
        shark = Shark();
        shark.eat(getFishByPoint({0, 0}));
    }
    Sea(const Sea& s) {
        fishes = s.fishes;
        shark = s.shark;
    }
    Shark& getShark() { return shark; }
    vector<Fish>& getFishes() { return fishes; }
    Fish& getFishByPoint(const Point& p) {
        for (Fish& fish : fishes) {
            if (fish.getPoint() == p) return fish;
        }
        return fishes[0];
    }
    void moveAllFishes() {
        for (Fish& fish : fishes) {
            if (!fish.isAlive()) continue;
            for (int i = 0; i < 8; i++) {
                Point next(fish.getPoint().x + dx[fish.getDirection()],
                           fish.getPoint().y + dy[fish.getDirection()]);
                if (next.x < 0 || next.x >= 4 || next.y < 0 || next.y >= 4 ||
                    shark.getPoint() == next) {  // 경계를 넘거나 상어가 있는 칸
                    fish.turn();
                    continue;
                }

                fish.swap(getFishByPoint(next));
                break;
            }
        }
    }
    vector<Point> getNextPoints() {
        vector<Point> points;
        for (int i = 1; i <= 3; i++) {
            Point next(shark.getPoint().x + dx[shark.getDirection()] * i,
                       shark.getPoint().y + dy[shark.getDirection()] * i);
            if (next.x < 0 || next.x >= 4 || next.y < 0 ||
                next.y >= 4)  // 경계를 넘는 칸
                break;

            if (getFishByPoint(next).isAlive()) points.push_back(next);
        }
        return points;
    }
};

void dfs(int& maxScore, Sea& sea) {
    sea.moveAllFishes();
    vector<Point> points = sea.getNextPoints();
    if (points.size() == 0) return;

    for (Point point : points) {
        Sea newSea(sea);
        newSea.getShark().eat(newSea.getFishByPoint(point));
        int score = newSea.getShark().getScore();
        if (score > maxScore) maxScore = score;
        dfs(maxScore, newSea);
    }

    return;
}

int main() {
    int a, b;
    vector<Fish> init_fishes;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            init_fishes.push_back({a, b - 1, Point(i, j)});
        }
    }
    sort(init_fishes.begin(), init_fishes.end());
    Sea sea(init_fishes);

    int maxScore = sea.getShark().getScore();
    dfs(maxScore, sea);
    cout << maxScore << "\n";

    return 0;
}