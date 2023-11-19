#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int left = 0, right = 0, diff = 2e9;
    while (right < n) {
        int temp = arr[right] - arr[left];

        if (temp < m) {
            right++;
            continue;
        }

        diff = min(diff, temp);
        if (diff == m) break;

        left++;
    }
    cout << diff << "\n";

    return 0;
}