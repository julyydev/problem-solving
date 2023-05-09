#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

void backtracking(vector<bool>& selected_stores, const int& total_store,
                  const int& total_house, int start, int select, const int& M,
                  const vector<vector<int>>& dist, int& min_sum) {
    if (select == M) {
        vector<int> min_dist(total_house, 1e8);
        for (int i = 0; i < total_store; i++) {
            if (selected_stores[i]) {
                for (int j = 0; j < total_house; j++)
                    min_dist[j] = min(min_dist[j], dist[j][i]);
            }
        }

        int sum = 0;
        for (int d : min_dist) sum += d;
        min_sum = min(sum, min_sum);
    }

    for (int i = start; i < total_store; i++) {
        if (selected_stores[i]) continue;

        selected_stores[i] = true;
        backtracking(selected_stores, total_store, total_house, i, select + 1,
                     M, dist, min_sum);
        selected_stores[i] = false;
    }
}

int main() {
    FASTIO();
    int N, M, min_sum = 1e8;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(N));
    vector<Point> houses, stores;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1)
                houses.push_back({i, j});
            else if (map[i][j] == 2)
                stores.push_back({i, j});
        }
    }

    vector<vector<int>> dist(houses.size(), vector<int>(stores.size()));
    for (int i = 0; i < houses.size(); i++)
        for (int j = 0; j < stores.size(); j++)
            dist[i][j] =
                abs(houses[i].x - stores[j].x) + abs(houses[i].y - stores[j].y);

    vector<bool> selected_stores(stores.size(), false);
    backtracking(selected_stores, stores.size(), houses.size(), 0, 0, M, dist,
                 min_sum);
    cout << min_sum << "\n";

    return 0;
}