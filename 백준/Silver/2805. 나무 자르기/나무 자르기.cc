// https://www.acmicpc.net/problem/1654
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, length, low, high, mid, max, sum;
    cin >> n >> m;
    vector<long long> vec;

    for (int i = 0; i < n; i++) {
        cin >> length;
        vec.push_back(length);
    }

    low = 0;
    high = *max_element(vec.begin(), vec.end());

    while (low <= high) {
        mid = (low + high) / 2;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (vec[i] - mid > 0 ? vec[i] - mid : 0);
        }

        if (sum >= m) {
            max = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << max;
}
