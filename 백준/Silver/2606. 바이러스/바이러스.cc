#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph(101);
bool isVisited[101];

void bfs(int n) {
    queue<int> q;
    q.push(n);
    isVisited[n] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto it = graph[cur].begin(); it < graph[cur].end(); it++) {
            if (!isVisited[*it]) {
                q.push(*it);
                isVisited[*it] = true;
            }
        }
    }
}

int result() {
    int sum = 0;
    for (int i = 0; i < 101; i++) {
        if (isVisited[i]) sum++;
    }

    return sum - 1;
}

int main() {
    int N, P;
    cin >> N >> P;
    for (int i = 0; i < P; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    bfs(1);
    cout << result() << "\n";

    return 0;
}