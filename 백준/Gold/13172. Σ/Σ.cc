#include <iostream>
#include <numeric>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const long long mod = 1000000007;

long long power(long long n, long long m) {
    if (m == 1) return n;
    if (m % 2 == 1) return n * power(n, m - 1) % mod;
    long long temp = power(n, m / 2);
    return temp * temp % mod;
}

int main() {
    FASTIO();
    long long M, N, S, sum = 0;
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> N >> S;
        long long g = gcd(N, S);
        N /= g, S /= g;
        sum += S * power(N, mod - 2) % mod;
        sum %= mod;
    }
    cout << sum << "\n";

    return 0;
}