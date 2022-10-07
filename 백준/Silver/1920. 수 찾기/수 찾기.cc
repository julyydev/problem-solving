// https://www.acmicpc.net/problem/1920
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> vec;
    ll num;
    int n, m, left, right, mid, check;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        left = 0, right = n - 1, check = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (vec[mid] > num)
                right = mid - 1;
            else if (vec[mid] < num)
                left = mid + 1;
            else {
                check = 1;
                break;
            }
        }
        cout << check << '\n';
    }
    
    return 0;
}
