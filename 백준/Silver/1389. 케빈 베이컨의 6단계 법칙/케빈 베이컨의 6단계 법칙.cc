#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int MAX = 999999;
vector<vector<int>> dist;

int main() {
    FASTIO();
    int N, M, A, B;
    cin >> N >> M;

    dist.resize(N + 1, vector<int>(N + 1, MAX));
    while (M--) {
        cin >> A >> B;
        dist[A][B] = dist[B][A] = 1;
    }
    for (int i = 1; i <= N; i++) dist[i][i] = 0;

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int min_num, min_sum = MAX;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) sum += dist[i][j];
        if (sum < min_sum) {
            min_num = i;
            min_sum = sum;
        }
    }
    cout << min_num << "\n";

    return 0;
}