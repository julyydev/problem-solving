#include <cmath>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N;
    cin >> N;

    vector<int> solutions(N);
    for (int i = 0; i < N; i++) cin >> solutions[i];

    int l = 0, r = N - 1, min_l = l, min_r = r,
        min_sum = solutions[l] + solutions[r];

    while (l < r) {
        int sum = solutions[l] + solutions[r];
        if (abs(sum) < abs(min_sum)) min_l = l, min_r = r, min_sum = sum;

        if (sum > 0)
            r--;
        else if (sum < 0)
            l++;
        else
            break;
    }

    cout << solutions[min_l] << " " << solutions[min_r] << "\n";

    return 0;
}
