// https://www.acmicpc.net/problem/10816
// written by julyy

/*
upper_bound, lower_bound (algorithm)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num;
    vector<int> vec;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << upper_bound(vec.begin(), vec.end(), num) - lower_bound(vec.begin(), vec.end(), num) << " ";
    }
}
