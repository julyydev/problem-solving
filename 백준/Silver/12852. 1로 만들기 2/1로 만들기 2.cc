#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;

vector<int> bfs() {
    vector<bool> isVisited(N + 1, false);
    queue<vector<int>> q;
    isVisited[N] = true;
    q.push({N});

    while (!q.empty()) {
        vector<int> cur = q.front(), temp;
        q.pop();

        if (cur.back() == 1) return cur;

        if (cur.back() % 3 == 0 && !isVisited[cur.back() / 3]) {
            temp = cur;
            temp.push_back(cur.back() / 3);
            q.push(temp);
            isVisited[temp.back()] = true;
        }
        if (cur.back() % 2 == 0 && !isVisited[cur.back() / 2]) {
            temp = cur;
            temp.push_back(cur.back() / 2);
            q.push(temp);
            isVisited[temp.back()] = true;
        }
        if (!isVisited[cur.back() - 1]) {
            temp = cur;
            temp.push_back(cur.back() - 1);
            q.push(temp);
            isVisited[temp.back()] = true;
        }
    }

    return {};
}

int main() {
    cin >> N;

    vector<int> answer = bfs();
    cout << answer.size() - 1 << "\n";
    for (int i : answer) cout << i << " ";
    cout << "\n";

    return 0;
}