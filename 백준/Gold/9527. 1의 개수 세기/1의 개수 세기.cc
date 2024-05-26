#include <bitset>
#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

typedef long long ll;

const int MAX_SIZE = 54;  // 10^16 to binary size is 54

ll base[MAX_SIZE + 1] = {
    0,
};

void get_base() {
    for (int i = 1; i <= MAX_SIZE; i++)
        base[i] = base[i - 1] * 2 + (1LL << (i - 1));
}

ll sum_base(ll n) { return base[n - 1] + 1; }

ll sum_binary(ll n) {
    if (n == 0) return 0;

    bitset bs = bitset<MAX_SIZE>(n);
    string s = bs.to_string().substr(bs.to_string().find('1'));

    ll l = s.length();
    ll pre = 0;
    ll sum = 0;
    for (int i = l; i >= 1; i--) {
        if (s[l - i] == '1') {
            sum += sum_base(i) + pre * (1LL << (i - 1));
            pre++;
        }
    }

    return sum;
}

int main() {
    FASTIO();
    ll a, b;
    cin >> a >> b;

    get_base();
    cout << sum_binary(b) - sum_binary(a - 1) << '\n';
    return 0;
}
