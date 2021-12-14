// https://www.acmicpc.net/problem/2869
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, V, day;
    cin >> A >> B >> V;

    day = (V - A) / (A - B) + 1;
    if ((V - A) % (A - B) != 0)
        day ++;
    cout << day;

    return 0;
}
