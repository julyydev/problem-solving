#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    int N, M, B, min_height = 256, max_height = 0;
    cin >> N >> M >> B;
    vector<vector<int>> vec(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> vec[i][j];
            if (vec[i][j] < min_height) min_height = vec[i][j];
            if (vec[i][j] > max_height) max_height = vec[i][j];
        }
    }

    int min_time = INT32_MAX, height = 0;
    for (int h = min_height; h <= max_height; h++) {
        int block = B, time = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                block += vec[i][j] - h;
                if (vec[i][j] > h)
                    time += 2 * abs(vec[i][j] - h);
                else if (vec[i][j] < h)
                    time += abs(vec[i][j] - h);
            }
        }
        if (block >= 0 && time <= min_time) min_time = time, height = h;
    }
    cout << min_time << " " << height << "\n";

    return 0;
}