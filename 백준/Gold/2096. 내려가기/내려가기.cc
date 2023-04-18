#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N;
    cin >> N;
    vector<int> input(3), min_sum(3, 0), max_sum(3, 0), temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) cin >> input[j];
        temp = min_sum;
        min_sum[0] = min(temp[0], temp[1]) + input[0];
        min_sum[1] = min(min(temp[0], temp[1]), temp[2]) + input[1];
        min_sum[2] = min(temp[1], temp[2]) + input[2];

        temp = max_sum;
        max_sum[0] = max(temp[0], temp[1]) + input[0];
        max_sum[1] = max(max(temp[0], temp[1]), temp[2]) + input[1];
        max_sum[2] = max(temp[1], temp[2]) + input[2];
    }

    cout << max(max(max_sum[0], max_sum[1]), max_sum[2]) << " "
         << min(min(min_sum[0], min_sum[1]), min_sum[2]) << "\n";

    return 0;
}