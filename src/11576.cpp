// https://www.acmicpc.net/problem/11576
// written by julyy

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll A, B, m, n, dec = 0;
    cin >> A >> B;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> n;
        dec += n * pow(A, m - 1 - i);
    }

    vector<ll> vec;
    while (dec != 0) {
        vec.push_back(dec % B);
        dec /= B; 
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        cout << vec[i] << ' ';
    }
    
    return 0;
}
