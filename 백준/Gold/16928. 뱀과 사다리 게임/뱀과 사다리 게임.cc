#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Data {
    int index, count;
    Data(int index, int count) : index(index), count(count) {}
};

vector<int> map;
vector<bool> isVisited;

int bfs(int start) {
    queue<Data> q;
    q.push({start, 0});
    isVisited[start] = true;

    while (!q.empty()) {
        Data cur = q.front();
        q.pop();
        if (cur.index == 100) return cur.count;

        for (int i = 1; i <= 6; i++) {
            Data next({cur.index + i, cur.count + 1});
            if (next.index > 100) break;
            if (isVisited[next.index]) continue;

            if (map[next.index] == 0)
                q.push(next);
            else {
                q.push({map[next.index], next.count});
                isVisited[map[next.index]] = true;
            }
            isVisited[next.index] = true;
        }
    }
    return -1;
}

int main() {
    int N, M, x, y;
    cin >> N >> M;
    map.resize(101, 0);
    isVisited.resize(101, false);

    while (N--) {
        cin >> x >> y;
        map[x] = y;
    }
    while (M--) {
        cin >> x >> y;
        map[x] = y;
    }

    cout << bfs(1) << "\n";

    return 0;
}