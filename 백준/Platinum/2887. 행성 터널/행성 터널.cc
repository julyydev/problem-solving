#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int id, x, y, z;
    Point() {}
    Point(int id, int x, int y, int z) : id(id), x(x), y(y), z(z) {}
};

struct Edge {
    int end, weight;
    Edge() {}
    Edge(int end, int weight) : end(end), weight(weight) {}
    bool operator<(const Edge& e) const { return weight > e.weight; }
};

int prim(int n, const vector<vector<Edge>>& graph) {
    int sum = 0;
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
    int n, x, y, z;
    cin >> n;

    vector<Point> planets(n);
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        planets[i] = {i, x, y, z};
    }

    sort(planets.begin(), planets.end(),
         [](Point first, Point second) -> bool { return first.x < second.x; });
    for (int i = 0; i < n - 1; i++) {
        graph[planets[i].id].push_back(
            {planets[i + 1].id, planets[i + 1].x - planets[i].x});
        graph[planets[i + 1].id].push_back(
            {planets[i].id, planets[i + 1].x - planets[i].x});
    }

    sort(planets.begin(), planets.end(),
         [](Point first, Point second) -> bool { return first.y < second.y; });
    for (int i = 0; i < n - 1; i++) {
        graph[planets[i].id].push_back(
            {planets[i + 1].id, planets[i + 1].y - planets[i].y});
        graph[planets[i + 1].id].push_back(
            {planets[i].id, planets[i + 1].y - planets[i].y});
    }

    sort(planets.begin(), planets.end(),
         [](Point first, Point second) -> bool { return first.z < second.z; });
    for (int i = 0; i < n - 1; i++) {
        graph[planets[i].id].push_back(
            {planets[i + 1].id, planets[i + 1].z - planets[i].z});
        graph[planets[i + 1].id].push_back(
            {planets[i].id, planets[i + 1].z - planets[i].z});
    }

    cout << prim(n, graph) << "\n";

    return 0;
}