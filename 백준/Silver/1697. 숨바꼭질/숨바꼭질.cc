#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<bool> isVisited(100001, false);

int bfs(int n, int k) {
    queue<pair<int, int>> q;
    q.push({n, 0});
    isVisited[n] = true;

    int total_time;
    while (!q.empty()) {
        int cur = q.front().first;
        int time = q.front().second;
        q.pop();
        if (cur == k) {
            total_time = time;
            break;
        }

        if (cur - 1 >= 0 && !isVisited[cur - 1]) {
            q.push({cur - 1, time + 1});
            isVisited[cur - 1] = true;
        }
        if (cur + 1 <= 100000 && !isVisited[cur + 1]) {
            q.push({cur + 1, time + 1});
            isVisited[cur + 1] = true;
        }
        if (2 * cur <= 100000 && !isVisited[2 * cur]) {
            q.push({2 * cur, time + 1});
            isVisited[2 * cur] = true;
        }
    }
    return total_time;
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << "\n";

    return 0;
}