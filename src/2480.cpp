// https://www.acmicpc.net/problem/2480
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b) {
        if (b == c)
            cout << 10000 + a * 1000;
        else
            cout << 1000 + a * 100;
    }
    else if (a > b) {
        if (c == a || c == b)
            cout << 1000 + c * 100;
        else if (c > a)
            cout << c * 100;
        else if (c < a)
            cout << a * 100;
    }
    else {
        if (c == a || c == b)
            cout << 1000 + c * 100;
        else if (c > b)
            cout << c * 100;
        else if (c < b)
            cout << b * 100;
    }
    
    return 0;
}
