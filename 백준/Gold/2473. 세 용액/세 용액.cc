#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N;
    cin >> N;

    vector<long long> solutions(N);
    for (int i = 0; i < N; i++) cin >> solutions[i];
    sort(solutions.begin(), solutions.end());

    int min_k = 0, min_l = 1, min_r = N - 1;
    long long min_sum = solutions[0] + solutions[1] + solutions[N - 1];

    for (int k = 0; k < N; k++) {
        int l = 0, r = N - 1;

        while (l < r) {
            if (l == k) {
                l++;
                continue;
            }
            if (r == k) {
                r--;
                continue;
            }

            long long sum = solutions[l] + solutions[r] + solutions[k];
            if (abs(sum) < abs(min_sum))
                min_k = k, min_l = l, min_r = r, min_sum = sum;

            if (sum > 0)
                r--;
            else if (sum < 0)
                l++;
            else
                break;
        }
    }

    if (min_k < min_l) {
        cout << solutions[min_k] << " " << solutions[min_l] << " "
             << solutions[min_r] << "\n";
    } else if (min_k > min_r) {
        cout << solutions[min_l] << " " << solutions[min_r] << " "
             << solutions[min_k] << "\n";
    } else {
        cout << solutions[min_l] << " " << solutions[min_k] << " "
             << solutions[min_r] << "\n";
    }

    return 0;
}
