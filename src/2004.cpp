// https://www.acmicpc.net/problem/2004
// written by julyy

/*
팩토리얼 계열에서 x 인수 개수 세기
n / x^1 + n / x^2 + ...
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m, num_of_two = 0, num_of_five = 0;
    cin >> n >> m;

    if (!m) {
        cout << 0;
        return 0;
    }
    if (2 * m > n)
        m = n - m;
    
    for (long long i = 2; i <= n; i *= 2)
        num_of_two += n / i;
    for (long long i = 5; i <= n; i *= 5)
        num_of_five += n / i;

    for (long long i = 2; i <= m; i *= 2)
        num_of_two -= m / i;
    for (long long i = 5; i <= n; i *= 5)
        num_of_five -= m / i;

    for (long long i = 2; i <= n - m; i *= 2)
        num_of_two -= (n - m) / i;
    for (long long i = 5; i <= n - m; i *= 5)
        num_of_five -= (n - m) / i;

    cout << min(num_of_two, num_of_five);
    
    return 0;
}
