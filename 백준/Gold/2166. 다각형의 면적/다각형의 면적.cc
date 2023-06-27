#include <cmath>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
};

class Polygon {
    int n;
    vector<Point> points;

   public:
    Polygon(int n) : n(n) {}

    void add_point(Point point) { points.push_back(point); }

    double get_area() {
        double result = 0;

        for (int i = 0; i < n; i++) {
            result += points[i % n].x * points[(i + 1) % n].y -
                      points[(i + 1) % n].x * points[i % n].y;
        }

        return round(5 * abs(result)) / 10;
    }
};

int main() {
    FASTIO();
    int n;
    double x, y;
    cin >> n;

    Polygon polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        polygon.add_point({x, y});
    }

    cout << fixed;
    cout.precision(1);
    cout << polygon.get_area() << "\n";

    return 0;
}