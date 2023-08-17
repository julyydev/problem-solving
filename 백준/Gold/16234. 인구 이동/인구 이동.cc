#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class Country {
    int n, min_diff, max_diff, day;
    vector<vector<int>> people;

   public:
    Country(int n, int min_diff, int max_diff, vector<vector<int>> people)
        : n(n),
          min_diff(min_diff),
          max_diff(max_diff),
          people(people),
          day(0) {}

   private:
    bool is_open_border(Point point1, Point point2) {
        int diff = abs(people[point1.x][point1.y] - people[point2.x][point2.y]);
        if (diff >= min_diff && diff <= max_diff)
            return true;
        else
            return false;
    }

    bool bfs(Point start, vector<vector<bool>>& is_visited) {
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};

        vector<Point> unions;
        int sum = 0;
        unions.push_back(start);
        sum += people[start.x][start.y];

        queue<Point> q;
        q.push(start);
        is_visited[start.x][start.y] = true;

        while (!q.empty()) {
            Point cur = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                Point next(cur.x + dx[i], cur.y + dy[i]);
                if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= n ||
                    is_visited[next.x][next.y])
                    continue;

                if (!is_open_border(cur, next)) continue;

                q.push(next);
                is_visited[next.x][next.y] = true;
                unions.push_back(next);
                sum += people[next.x][next.y];
            }
        }

        int new_people = sum / unions.size();
        for (const Point& point : unions) people[point.x][point.y] = new_people;

        if (unions.size() != 1)
            return true;
        else
            return false;
    }

    bool visit_all_area() {
        vector<vector<bool>> is_visited(n, vector<bool>(n, false));
        bool check = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (is_visited[i][j]) continue;
                if (bfs({i, j}, is_visited)) check = true;
            }
        }
        return check;
    }

   public:
    void move_population() {
        while (visit_all_area()) day++;
    }

    int get_day() { return day; }
};

int main() {
    FASTIO();
    int N, L, R;
    cin >> N >> L >> R;
    vector<vector<int>> init_people(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> init_people[i][j];

    Country country(N, L, R, init_people);
    country.move_population();
    cout << country.get_day() << "\n";

    return 0;
}