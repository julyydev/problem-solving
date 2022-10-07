// https://www.acmicpc.net/problem/9613
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    vector<long> vec;
    int t, n;
    long num, sum;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        sum = 0;
        vec.clear();
        for (int j = 0; j < n; j++) {
            cin >> num;
            vec.push_back(num);
        }
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++)
                sum += gcd(vec[j], vec[k]);
        }
        cout << sum << '\n';
    }
    
    return 0;
}
