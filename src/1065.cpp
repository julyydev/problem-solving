// https://www.acmicpc.net/problem/1065
// written by julyy

#include <iostream>
using namespace std;

bool isHansoo(int n) {
    if (n < 100)
        return true;
    if (n == 1000)
        return false;
    if (2 * (n / 10 % 10) == (n / 100) + (n % 10))
        return true;
    else
        return false;
}

int main() {
    int n, count = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if(isHansoo(i))
            count++;
    }
    cout << count << '\n';

    return 0;
}