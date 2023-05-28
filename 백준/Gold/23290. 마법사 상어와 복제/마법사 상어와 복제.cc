#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

bool isOutOfBounds(Point point) {
    return point.x < 0 || point.x >= 4 || point.y < 0 || point.y >= 4;
}

class Fish {
    Point point;
    int direction;  // 0 ~ 7 : ←, ↖, ↑, ↗, →, ↘, ↓, ↙
    int number;

   public:
    Fish() {}
    Fish(Point point, int direction, int number)
        : point(point), direction(direction), number(number) {}
    bool operator==(const Fish& f) const {
        return point == f.point && direction == f.direction;
    }
    Point getPoint() { return point; }
    Point getPostMovePoint() {
        const int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
        const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

        return {point.x + dx[direction], point.y + dy[direction]};
    }
    void turn() { direction = (direction + 7) % 8; }
    void move() { point = getPostMovePoint(); }
    int getDirection() { return direction; }
    int getNumber() { return number; }
};

class Shark {
    Point point;

   public:
    Shark() {}
    Shark(Point point) {}
    Point getPoint() { return point; }
    void setPoint(Point value) { point = value; }
};

struct Tile {
    int fish_number, smell_duration;
    Tile(int fish_number, int smell_duration)
        : fish_number(fish_number), smell_duration(smell_duration) {}
};

class Wizzard {
    Shark shark;
    vector<Fish> fishes;
    vector<vector<Tile>> map;

   public:
    Wizzard(Point shark_point, vector<Fish> fishes) : fishes(fishes) {
        shark.setPoint(shark_point);
        map.assign(4, vector<Tile>(4, {0, 0}));
        for (Fish& fish : fishes) {
            map[fish.getPoint().x][fish.getPoint().y].fish_number++;
        }
    }

   private:
    void sortFishes() {
        vector<bool> isChecked(fishes.size(), false);
        vector<Fish> new_fishes;

        for (int i = 0; i < fishes.size() - 1; i++) {
            if (isChecked[i]) continue;
            int sum = fishes[i].getNumber();
            for (int j = i + 1; j < fishes.size(); j++) {
                if (fishes[i] == fishes[j]) {
                    sum += fishes[j].getNumber();
                    isChecked[j] = true;
                }
            }
            new_fishes.push_back(
                {fishes[i].getPoint(), fishes[i].getDirection(), sum});
            isChecked[i] = true;
        }

        if (!isChecked[fishes.size() - 1])
            new_fishes.push_back(fishes[fishes.size() - 1]);

        fishes = new_fishes;
    }

    void moveAllFishes() {
        for (Fish& fish : fishes) {
            for (int i = 0; i < 8; i++) {
                Point temp = fish.getPostMovePoint();
                if (isOutOfBounds(temp) ||
                    map[temp.x][temp.y].smell_duration > 0 ||
                    shark.getPoint() == temp) {
                    fish.turn();
                    continue;
                }

                map[fish.getPoint().x][fish.getPoint().y].fish_number -=
                    fish.getNumber();
                fish.move();
                map[fish.getPoint().x][fish.getPoint().y].fish_number +=
                    fish.getNumber();
                break;
            }
        }
    }
    void moveShark() {
        const int dx[4] = {-1, 0, 1, 0};
        const int dy[4] = {0, -1, 0, 1};
        vector<Point> route;
        int max_sum = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    int sum = 0;
                    Point temp1(shark.getPoint().x + dx[i],
                                shark.getPoint().y + dy[i]);
                    if (isOutOfBounds(temp1)) continue;
                    Point temp2(temp1.x + dx[j], temp1.y + dy[j]);
                    if (isOutOfBounds(temp2)) continue;
                    Point temp3(temp2.x + dx[k], temp2.y + dy[k]);
                    if (isOutOfBounds(temp3)) continue;

                    sum += (map[temp1.x][temp1.y].fish_number < 0
                                ? 0
                                : map[temp1.x][temp1.y].fish_number);
                    sum += (map[temp2.x][temp2.y].fish_number < 0
                                ? 0
                                : map[temp2.x][temp2.y].fish_number);

                    if (!(temp1 == temp3)) {
                        sum += (map[temp3.x][temp3.y].fish_number < 0
                                    ? 0
                                    : map[temp3.x][temp3.y].fish_number);
                    }

                    if (route.size() == 0) route = {temp1, temp2, temp3};

                    if (sum > max_sum) {
                        max_sum = sum;
                        route = {temp1, temp2, temp3};
                    }
                }
            }
        }

        for (Point& point : route) {
            auto it = fishes.begin();
            while (it != fishes.end()) {
                if ((*it).getPoint() == point)
                    it = fishes.erase(it);
                else
                    ++it;
            }

            if (map[point.x][point.y].fish_number > 0) {
                map[point.x][point.y].fish_number = 0;
                map[point.x][point.y].smell_duration = 3;
            }
        }
        shark.setPoint(route[2]);
    }
    void evaporateSmell() {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (map[i][j].smell_duration > 0) map[i][j].smell_duration--;
    }
    void duplicateAllFishes(vector<Fish>& temp) {
        fishes.insert(fishes.end(), temp.begin(), temp.end());
        for (Fish& fish : temp)
            map[fish.getPoint().x][fish.getPoint().y].fish_number +=
                fish.getNumber();
        sortFishes();
    }

   public:
    void duplicate() {
        vector<Fish> temp = fishes;  // step.1
        moveAllFishes();             // step.2
        moveShark();                 // step.3
        evaporateSmell();            // step.4
        duplicateAllFishes(temp);    // step.5
    }
    int getFishNumber() {
        int sum = 0;
        for (Fish& fish : fishes) sum += fish.getNumber();
        return sum;
    }
};

int main() {
    FASTIO();
    int M, S, x, y, d;
    cin >> M >> S;
    vector<Fish> init_fishes(M);

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> d;
        init_fishes[i] = {{x - 1, y - 1}, d - 1, 1};
    }
    cin >> x >> y;
    Wizzard wizzard({x - 1, y - 1}, init_fishes);

    while (S--) wizzard.duplicate();
    cout << wizzard.getFishNumber() << "\n";

    return 0;
}