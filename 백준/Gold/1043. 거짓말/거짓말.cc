#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

void bfs(int start, vector<bool>& is_person_known_truth,
         const vector<vector<bool>>& graph, const int& n) {
    queue<int> q;
    vector<bool> isVisited(n + 1, false);
    q.push(start);
    isVisited[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        is_person_known_truth[cur] = true;

        for (int i = 1; i < n + 1; i++) {
            if (!graph[cur][i] || isVisited[i]) continue;
            q.push(i);
            isVisited[i] = true;
        }
    }

    return;
}

int main() {
    FASTIO();
    int N, M, T, P;
    cin >> N >> M >> T;
    vector<int> known_people(T);
    vector<bool> is_person_known_truth(N + 1, false);
    vector<vector<int>> party_people(M);
    vector<vector<bool>> graph(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < T; i++) cin >> known_people[i];
    for (int i = 0; i < M; i++) {
        cin >> P;
        vector<int> temp(P);
        for (int j = 0; j < P; j++) cin >> temp[j];
        party_people[i] = temp;

        for (int j = 0; j < P - 1; j++)
            for (int k = j + 1; k < P; k++)
                graph[temp[j]][temp[k]] = graph[temp[k]][temp[j]] = true;
    }

    for (int i = 0; i < T; i++)
        bfs(known_people[i], is_person_known_truth, graph, N);

    int count = 0;
    for (int i = 0; i < M; i++) {
        bool check = true;
        for (int p : party_people[i]) {
            if (is_person_known_truth[p]) {
                check = false;
                break;
            }
        }
        if (check) count++;
    }

    cout << count << "\n";

    return 0;
}