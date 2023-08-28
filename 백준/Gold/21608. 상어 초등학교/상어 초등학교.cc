#include <iostream>
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

struct Student {
    int num;
    set<int> favorites;
    Student() {}
    Student(int num, set<int> favorites) : num(num), favorites(favorites) {}
};

struct Seat {
    int num_favorite_near;
    int num_empty_near;
    Point point;

    Seat() {}
    Seat(int num_favorite_near, int num_empty_near, Point point)
        : num_favorite_near(num_favorite_near),
          num_empty_near(num_empty_near),
          point(point) {}
    bool operator<(const Seat& s) const {
        if (num_favorite_near == s.num_favorite_near &&
            num_empty_near == s.num_empty_near)
            return s.point < point;
        if (num_favorite_near == s.num_favorite_near)
            return num_empty_near < s.num_empty_near;
        return num_favorite_near < s.num_favorite_near;
    }
};

class School {
    int n;
    vector<Student> students;
    vector<vector<int>> seats;

    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

   public:
    School(int n, vector<Student> students)
        : n(n), students(students), seats(n, vector<int>(n, 0)) {}

   private:
    void set_student_seat(const Student& student) {
        Seat target(0, 0, {n, n});
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (seats[i][j] != 0) continue;

                int num_favorite_near = 0, num_empty_near = 0;
                for (int k = 0; k < 4; k++) {
                    Point near(i + dx[k], j + dy[k]);
                    if (near.x < 0 || near.x >= n || near.y < 0 || near.y >= n)
                        continue;

                    if (student.favorites.find(seats[near.x][near.y]) !=
                        student.favorites.end())
                        num_favorite_near++;
                    else if (seats[near.x][near.y] == 0)
                        num_empty_near++;
                }

                Seat temp(num_favorite_near, num_empty_near, {i, j});
                target = max(target, temp);
            }
        }
        seats[target.point.x][target.point.y] = student.num;
    }

   public:
    void arrange_seats() {
        for (const Student& student : students) set_student_seat(student);
    }

    int get_satisfaction() {
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int num_favorite_near = 0;
                for (const Student& student : students) {
                    if (student.num != seats[i][j]) continue;

                    for (int k = 0; k < 4; k++) {
                        Point near(i + dx[k], j + dy[k]);
                        if (near.x < 0 || near.x >= n || near.y < 0 ||
                            near.y >= n)
                            continue;

                        if (student.favorites.find(seats[near.x][near.y]) !=
                            student.favorites.end())
                            num_favorite_near++;
                    }
                }

                if (num_favorite_near == 1)
                    sum += 1;
                else if (num_favorite_near == 2)
                    sum += 10;
                else if (num_favorite_near == 3)
                    sum += 100;
                else if (num_favorite_near == 4)
                    sum += 1000;
            }
        }

        return sum;
    }
};

int main() {
    FASTIO();
    int N, num, f;
    cin >> N;

    vector<Student> students(N * N);
    for (int i = 0; i < N * N; i++) {
        cin >> num;
        set<int> favorites;
        for (int j = 0; j < 4; j++) {
            cin >> f;
            favorites.insert(f);
        }
        students[i] = Student(num, favorites);
    }

    School school(N, students);
    school.arrange_seats();
    cout << school.get_satisfaction() << "\n";

    return 0;
}