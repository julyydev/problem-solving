#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const string d[4] = {"↑", "↓", "←", "→"};

struct Point {
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
};

struct Cell {
    int shark_num, duration;  // 0이면 상어가 없는 칸
    Cell() {}
    Cell(int shark_num, int duration)
        : shark_num(shark_num), duration(duration) {}
};

class Shark {
    int num;                             // 쫏겨날때만 0으로 변화
    int direction;                       // 매 이동마다 변화
    Point point;                         // 매 이동마다 변화
    const vector<vector<int>> priority;  // 입력 받은 후 부터는 불변

   public:
    Shark(int num, int direction, Point point, vector<vector<int>> priority)
        : num(num), direction(direction), point(point), priority(priority) {}

   public:
    bool isKickedOut() { return num == 0; }
    void kickedOut() { num = 0; }
    Point getNextPointByPriority(const int& map_size,
                                 const vector<vector<Cell>>& map) {
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, -1, 1};
        bool check = false;
        Point temp;
        for (int i : priority[direction]) {
            Point next(point.x + dx[i], point.y + dy[i]);
            if (next.x < 0 || next.x >= map_size || next.y < 0 ||
                next.y >= map_size)  // 경계를 벗어나는 경우
                continue;
            if (map[next.x][next.y].shark_num == num) {
                if (check) continue;
                direction = i;
                temp = next;
                check = true;
            } else if (map[next.x][next.y].shark_num == 0) {
                direction = i;
                return next;
            }
        }
        return temp;
    }
    void move(const Point& next, vector<vector<Cell>>& map,
              vector<int>& kickSharkNum, const int& max_duration) {
        if (map[next.x][next.y].shark_num == 0 ||
            map[next.x][next.y].shark_num == num) {  // 빈 칸인 경우
            point = next;
            map[next.x][next.y].shark_num = num;
            map[next.x][next.y].duration = max_duration + 1;
        } else if (map[next.x][next.y].shark_num < num) {
            kickSharkNum.push_back(num);
        } else {
            point = next;
            map[next.x][next.y].shark_num = num;
            map[next.x][next.y].duration = max_duration + 1;
            kickSharkNum.push_back(map[next.x][next.y].shark_num);
        }
    }
};

class Sea {
    vector<vector<Cell>> map;
    vector<Shark> sharks;
    int rest_shark;
    const int map_size;
    const int max_duration;

   public:
    Sea(int N, int M, int K, vector<vector<int>> init_map,
        vector<int> init_direction, vector<vector<vector<int>>> init_priority)
        : map_size(N), rest_shark(M), max_duration(K) {
        vector<Point> points(M);
        map.resize(N, vector<Cell>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                map[i][j] = {init_map[i][j], init_map[i][j] ? K : 0};
                if (init_map[i][j]) points[init_map[i][j] - 1] = {i, j};
            }
        }
        for (int i = 0; i < M; i++) {
            Shark s(i + 1, init_direction[i], points[i], init_priority[i]);
            sharks.push_back(s);
        }
    }

   private:
    void decreaseAllDuration() {
        for (int i = 0; i < map_size; i++) {
            for (int j = 0; j < map_size; j++) {
                if (map[i][j].shark_num) {
                    map[i][j].duration--;
                    if (map[i][j].duration == 0) map[i][j].shark_num = 0;
                }
            }
        }
    }

   public:
    void moveAll() {
        vector<Point> nextPoints;
        vector<int> kickSharkNum;
        for (Shark& shark : sharks) {
            if (shark.isKickedOut()) continue;
            nextPoints.push_back(shark.getNextPointByPriority(map_size, map));
        }
        int i = 0;
        for (Shark& shark : sharks) {
            if (shark.isKickedOut()) continue;
            shark.move(nextPoints[i++], map, kickSharkNum, max_duration);
        }
        for (int k : kickSharkNum) {
            sharks[k - 1].kickedOut();
            rest_shark--;
        }
        decreaseAllDuration();
    }
    int getRestShark() { return rest_shark; }
};

int main() {
    FASTIO();
    int N, M, K, d;
    cin >> N >> M >> K;
    vector<vector<int>> init_map(N, vector<int>(N));
    vector<int> init_direction(M);
    vector<vector<vector<int>>> init_priority(
        M, vector<vector<int>>(4, vector<int>(4)));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> init_map[i][j];

    for (int i = 0; i < M; i++) {
        cin >> d;
        init_direction[i] = d - 1;
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++) {
                cin >> d;
                init_priority[i][j][k] = d - 1;
            }

    Sea sea(N, M, K, init_map, init_direction, init_priority);
    int time = 0;
    while (1) {
        time++;
        sea.moveAll();
        if (sea.getRestShark() == 1) {
            cout << time << "\n";
            return 0;
        }
        if (time == 1000) {
            cout << "-1\n";
            return 0;
        }
    }

    return 0;
}