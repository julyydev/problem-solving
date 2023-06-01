#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int N, S;
    cin >> N >> S;
    vector<int> nums(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> nums[i];
        nums[i] += nums[i - 1];
    }

    if (nums[N] < S) {
        cout << "0\n";
        return 0;
    }

    int left = 0, right = 0, min_length = 100000;

    while (left != N || right != N) {
        if (nums[right] - nums[left] >= S) {
            if (right - left < min_length) min_length = right - left;
            left++;
        } else {
            if (right == N)
                left++;
            else
                right++;
        }
    }

    cout << min_length << "\n";

    return 0;
}