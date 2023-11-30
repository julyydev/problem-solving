#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int p, n, count = 0;
    cin >> p >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (p >= 200) break;

        p += arr[i];
        count++;
    }

    cout << count << "\n";

    return 0;
}