// https://www.acmicpc.net/problem/1654
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, n, length, count, start, end, mid, max;
    cin >> k >> n;

    vector<long long> vec;
    for (int i = 0; i < k; i++) {
        cin >> length;
        vec.push_back(length);
    }

    start = 1;
    end = *max_element(vec.begin(), vec.end());

    while (start <= end) {
        mid = (start + end) / 2;
        count = 0;
        for (int i = 0; i < k; i++) {
            count += vec[i] / mid;
        }

        if (count >= n) {
            start = mid + 1;
            max = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << max;
}
