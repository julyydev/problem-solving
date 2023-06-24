#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;

    vector<int> arr(n), dp1(n, 1), dp2(n, 1);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j]) dp1[i] = max(dp1[i], dp1[j] + 1);

    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (arr[i] > arr[j]) dp2[i] = max(dp2[i], dp2[j] + 1);

    int high = 1;
    for (int i = 0; i < n; i++) high = max(high, dp1[i] + dp2[i] - 1);

    cout << high << "\n";

    return 0;
}