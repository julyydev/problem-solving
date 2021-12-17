// https://www.acmicpc.net/problem/2981
// written by julyy

/*
약수 구하는 것 i * i로 하면 시간 절약 가능
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long gcd(long a, long b) {
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long n, g;
    vector<long long> vec, div;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);
    }
    sort(vec.begin(), vec.end());

    g = vec[1] - vec[0];
    for (int i = 2; i < N; i++) {
        g = gcd(g, vec[i] - vec[i - 1]);
    }

    for (long long i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            div.push_back(i);
            if (i * i != g)
                div.push_back(g / i);
        }
    }
    div.push_back(g);
    sort(div.begin(), div.end());

    for (int i = 0; i < div.size(); i++)
        cout << div[i] << ' ';
    
    return 0;
}
