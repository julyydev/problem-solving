// https://www.acmicpc.net/problem/2292
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, num = 1, count = 1;
    cin >> n;

    while (num < n)
        num += 6 * count++;
    cout << count;

    return 0;
}
