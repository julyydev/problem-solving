// https://www.acmicpc.net/problem/10824
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, c, d;
    long long sum = 0;
    cin >> a >> b >> c >> d;
    a += b, c += d;
    sum += stoll(a);
    sum += stoll(c);
    cout << sum;

    return 0;
}
