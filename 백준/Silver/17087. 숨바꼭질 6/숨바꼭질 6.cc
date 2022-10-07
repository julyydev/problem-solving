// https://www.acmicpc.net/problem/17087
// written by julyy

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll s, a, g;
    vector<ll> vec;
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        vec.push_back(abs(s - a));
    }

    g = vec[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, vec[i]);
    }
    cout << g;
    
    return 0;
}
