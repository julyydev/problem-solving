#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int T;
    cin >> T;

    while (T--) {
        vector<long long> arr(3);
        for (int i = 0; i < 3; i++) cin >> arr[i];
        sort(arr.begin(), arr.end());
        cout << (arr[0] + arr[1]) * (arr[0] + arr[1]) + arr[2] * arr[2] << "\n";
    }

    return 0;
}
