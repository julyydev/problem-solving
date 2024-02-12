#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int t, n;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        while (n > 2) {
            for (int i = 0; i < (n + 1) / 2; i++) {
                nums[i] += nums[n - i - 1];
            }
            n = (n + 1) / 2;
        }

        cout << "Case #" << c << ": " << (nums[0] > nums[1] ? "Alice" : "Bob")
             << "\n";
    }

    return 0;
}