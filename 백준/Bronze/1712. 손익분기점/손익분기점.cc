// https://www.acmicpc.net/problem/1712
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c - b <= 0) {
        cout << -1;
        return 0;
    }
    
    int point = a / (c - b) + 1;
    cout << point;
    return 0;
}

