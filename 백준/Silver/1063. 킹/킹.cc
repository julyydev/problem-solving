#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
};

void move(Point& king, Point& rock, int dx, int dy) {
    Point king_next(king.x + dx, king.y + dy);
    if (king_next.x < 0 || king_next.x >= 8 || king_next.y < 0 ||
        king_next.y >= 8)
        return;
    if (king_next == rock) {
        Point rock_next(rock.x + dx, rock.y + dy);
        if (rock_next.x < 0 || rock_next.x >= 8 || rock_next.y < 0 ||
            rock_next.y >= 8)
            return;

        rock = rock_next;
    }
    king = king_next;
}

int main() {
    FASTIO();
    char c1, c2;
    int r1, r2, n;
    cin >> c1 >> r1 >> c2 >> r2 >> n;
    Point king(8 - r1, c1 - 'A'), rock(8 - r2, c2 - 'A');

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "R")
            move(king, rock, 0, 1);
        else if (s == "L")
            move(king, rock, 0, -1);
        else if (s == "B")
            move(king, rock, 1, 0);
        else if (s == "T")
            move(king, rock, -1, 0);
        else if (s == "RT")
            move(king, rock, -1, 1);
        else if (s == "LT")
            move(king, rock, -1, -1);
        else if (s == "RB")
            move(king, rock, 1, 1);
        else if (s == "LB")
            move(king, rock, 1, -1);
    }
    cout << (char)('A' + king.y) << 8 - king.x << "\n"
         << (char)('A' + rock.y) << 8 - rock.x << "\n";

    return 0;
}