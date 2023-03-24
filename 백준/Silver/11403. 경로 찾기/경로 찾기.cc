#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int MAX = 999999;
vector<vector<int>> dist;

int main() {
    FASTIO();
    int N, x;
    cin >> N;

    dist.resize(N, vector<int>(N, MAX));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> x;
            if (x == 0)
                dist[i][j] = MAX;
            else
                dist[i][j] = 1;
        }
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (dist[i][j] == MAX ? 0 : 1) << " ";
        }
        cout << "\n";
    }

    return 0;
}