// https://www.acmicpc.net/problem/1193
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0, layer = 0;
    cin >> n;

    while (n > sum)
        sum += ++layer;
    sum -= layer;
    
    if (layer % 2 == 1)
        cout << layer + 1 - n + sum << "/" << n - sum;
    else
        cout << n - sum << "/" << layer + 1 - n + sum; 

    return 0;
}
