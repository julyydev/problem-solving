// https://www.acmicpc.net/problem/11720
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;

    string str;
    cin >> str;

    for (int i = 0; i < n; i++) {
        sum += str[i] - 48;
    }
    cout << sum << '\n';

    return 0;
}
