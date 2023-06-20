#include <iostream>
#include <map>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int R, C;

struct Point {
    int r, c;
    Point() {}
    Point(int r, int c) : r(r), c(c) {}

    bool operator<(const Point& p) const {
        if (r == p.r) return c < p.c;
        return r < p.r;
    }
};

class Shark {
    int id;
    bool is_alive;
    Point point;
    int speed, direction, size;

   public:
    Shark() {}
    Shark(int id, Point point, int speed, int direction, int size)
        : id(id),
          is_alive(true),
          point(point),
          speed(speed),
          direction(direction),
          size(size) {}

    void die() { is_alive = false; }

    bool is_dead() { return !is_alive; }

    void turn() {
        if (direction == 0)
            direction = 1;
        else if (direction == 1)
            direction = 0;
        else if (direction == 2)
            direction = 3;
        else
            direction = 2;
    }

    void move() {
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        int time = speed;
        if (direction == 0 || direction == 1)
            time %= (R - 1) * 2;
        else
            time %= (C - 1) * 2;

        for (int i = 0; i < time; i++) {
            Point next(point.r + dr[direction], point.c + dc[direction]);
            if (next.r < 0 || next.r >= R || next.c < 0 || next.c >= C) {
                turn();
                next = {point.r + dr[direction], point.c + dc[direction]};
            }
            point = next;
        }
    }

    Point get_point() { return point; }

    int get_size() { return size; }
};

class FishingKing {
    int total_size;
    int position;
    vector<Shark> sharks;
    map<Point, int> shark_map;

   public:
    FishingKing(const vector<Shark>& init_sharks)
        : total_size(0), position(0), sharks(init_sharks) {
        for (int id = 0; id < sharks.size(); id++)
            shark_map.insert({sharks[id].get_point(), id});
    }

   private:
    void fishing() {
        for (int i = 0; i < R; i++) {
            if (shark_map.find({i, position}) == shark_map.end()) continue;

            int id = shark_map[{i, position}];
            total_size += sharks[id].get_size();
            sharks[id].die();
            break;
        }
    }

    void move_all_sharks() {
        map<Point, int> new_map;
        for (int id = 0; id < sharks.size(); id++) {
            if (sharks[id].is_dead()) continue;
            sharks[id].move();

            Point point = sharks[id].get_point();
            if (new_map.find(point) == new_map.end())
                new_map.insert({point, id});
            else {
                int existing_id = new_map[point];
                if (sharks[existing_id].get_size() < sharks[id].get_size()) {
                    sharks[existing_id].die();
                    new_map[point] = id;
                } else
                    sharks[id].die();
            }
        }

        shark_map = new_map;
    }

   public:
    void action() {
        while (position < C) {
            fishing();
            move_all_sharks();
            position++;
        }
    }

    int get_total_size() { return total_size; }
};

int main() {
    FASTIO();
    int M, r, c, s, d, z;
    cin >> R >> C >> M;
    vector<Shark> init_shark(M);

    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> d >> z;
        init_shark[i] = Shark(i, {r - 1, c - 1}, s, d - 1, z);
    }

    FishingKing fishing_king(init_shark);
    fishing_king.action();
    cout << fishing_king.get_total_size() << "\n";

    return 0;
}