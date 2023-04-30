#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int point, time;
    Data(int point, int time) : point(point), time(time) {}
};

pair<int, int> bfs(const int& start, const int& target) {
    int min_time = -1, count = 0;
    queue<Data> q;
    vector<int> time(100001, -1);
    q.push({start, 0});
    time[start] = 0;

    while (!q.empty()) {
        Data cur = q.front();
        q.pop();

        if (min_time != -1 && cur.time > min_time) break;

        if (cur.point == target) {
            if (min_time == -1) min_time = cur.time;
            count++;
            continue;
        }

        if (cur.point * 2 <= 100000 &&
            (time[cur.point * 2] == -1 || cur.time < time[cur.point * 2])) {
            q.push({cur.point * 2, cur.time + 1});
            time[cur.point * 2] = cur.time + 1;
        }
        if (cur.point + 1 <= 100000 &&
            (time[cur.point + 1] == -1 || cur.time < time[cur.point + 1])) {
            q.push({cur.point + 1, cur.time + 1});
            time[cur.point + 1] = cur.time + 1;
        }
        if (cur.point - 1 >= 0 &&
            (time[cur.point - 1] == -1 || cur.time < time[cur.point - 1])) {
            q.push({cur.point - 1, cur.time + 1});
            time[cur.point - 1] = cur.time + 1;
        }
    }

    return {min_time, count};
}

int main() {
    FASTIO();
    int N, K;
    cin >> N >> K;
    auto [time, count] = bfs(N, K);
    cout << time << "\n" << count << "\n";

    return 0;
}