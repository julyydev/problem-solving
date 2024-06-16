#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Segment {
    int x, y;
    Segment() {}
    Segment(int x, int y) : x(x), y(y) {}
};

class SegmentSet {
    int size = 0;
    vector<Segment> set;
    vector<vector<int>> routes;

   public:
    SegmentSet() {}

    void insert(int x, int y) {
        size++;
        routes.push_back({});
        Segment new_segment(x, y);

        for (int i = 0; i < size - 1; i++) {
            if (can_move(set[i], new_segment)) routes[i].push_back(size - 1);
            if (can_move(new_segment, set[i])) routes[size - 1].push_back(i);
        }

        set.push_back({x, y});
    }

    int query(int a, int b) {
        queue<int> q;
        vector<bool> visited(size, false);

        q.push(a - 1);
        visited[a - 1] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == b - 1) return 1;

            for (int route : routes[cur]) {
                if (visited[route]) continue;
                q.push(route);
                visited[route] = true;
            }
        }

        return 0;
    }

   private:
    bool can_move(const Segment& s1, const Segment& s2) {
        return (s2.x < s1.x && s1.x < s2.y) || (s2.x < s1.y && s1.y < s2.y);
    }
};

int main() {
    FASTIO();
    int n, q, x, y;
    cin >> n;

    SegmentSet segment_set;
    while (n--) {
        cin >> q >> x >> y;
        if (q == 1)
            segment_set.insert(x, y);
        else
            cout << segment_set.query(x, y) << "\n";
    }

    return 0;
}
