// https://www.acmicpc.net/problem/1977
// written by julyy

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n, sum = 0, min, i;
    cin >> m >> n;
    i = ceil(sqrt(m));
    min = i * i;
    for (i; i <= floor(sqrt(n)); i++) {
        sum += i * i;
    }
    if (sum == 0)
        cout << -1;
    else
        cout << sum << '\n' << min;
    
    return 0;
}
