#include <deque>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int point, time;
    Data(int point, int time) : point(point), time(time) {}
};

int bfs(const int& start, const int& target) {
    deque<Data> dq;
    vector<int> isVisited(100001, false);
    dq.push_back({start, 0});
    isVisited[start] = true;

    while (!dq.empty()) {
        Data cur = dq.front();
        dq.pop_front();

        if (cur.point == target) return cur.time;

        if (cur.point * 2 <= 100000 && !isVisited[cur.point * 2]) {
            dq.push_front({cur.point * 2, cur.time});
            isVisited[cur.point * 2] = true;
        }
        if (cur.point + 1 <= 100000 && !isVisited[cur.point + 1]) {
            dq.push_back({cur.point + 1, cur.time + 1});
            isVisited[cur.point + 1] = true;
        }
        if (cur.point - 1 >= 0 && !isVisited[cur.point - 1]) {
            dq.push_back({cur.point - 1, cur.time + 1});
            isVisited[cur.point - 1] = true;
        }
    }

    return -1;
}

int main() {
    FASTIO();
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K) << "\n";

    return 0;
}