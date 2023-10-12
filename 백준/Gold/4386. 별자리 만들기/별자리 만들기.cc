#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const double INF = 100000000;

struct Point {
    int id;
    double x, y;
    Point() {}
    Point(int id, double x, double y) : id(id), x(x), y(y) {}
};

struct Edge {
    int end;
    double weight;
    Edge() {}
    Edge(int end, double weight) : end(end), weight(weight) {}
    bool operator<(const Edge& e) const { return weight > e.weight; }
};

double prim(int n, const vector<vector<Edge>>& graph) {
    double sum = 0;
    priority_queue<Edge> pq;
    vector<bool> is_added(n, false);

    is_added[0] = true;
    for (auto e : graph[0]) pq.push(e);

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        if (is_added[cur.end]) continue;

        is_added[cur.end] = true;
        sum += cur.weight;

        for (auto e : graph[cur.end]) pq.push(e);
    }

    return sum;
}

int main() {
    FASTIO();
    int n;
    double x, y;
    cin >> n;
    vector<Point> stars(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        stars[i] = {i, x, y};
    }

    vector<vector<Edge>> graph(n, vector<Edge>(n));
    for (int i = 0; i < n; i++) graph[i][i] = {i, INF};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            double d =
                sqrt((stars[i].x - stars[j].x) * (stars[i].x - stars[j].x) +
                     (stars[i].y - stars[j].y) * (stars[i].y - stars[j].y));
            graph[i][j] = {j, d};
            graph[j][i] = {i, d};
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << prim(n, graph) << "\n";

    return 0;
}