// https://www.acmicpc.net/problem/5086
// written by julyy

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;

        if (a > b && a % b == 0)
            cout << "multiple" << '\n';
        else if  (a < b && b % a == 0)
            cout << "factor" << '\n';
        else
            cout << "neither" << '\n';
    }
    
    return 0;
}