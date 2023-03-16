#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, x;
    cin >> N >> M;
    vector<vector<int>> vec(N, vector<int>(M, 0));

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> x;
                vec[i][j] += x;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}