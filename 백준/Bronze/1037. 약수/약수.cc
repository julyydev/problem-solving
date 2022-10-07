// https://www.acmicpc.net/problem/1037
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
    ll n, divisor;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> divisor;
        vec.push_back(divisor);
    }
    sort(vec.begin(), vec.end());
    cout << vec.front() * vec.back();

    return 0;
}
