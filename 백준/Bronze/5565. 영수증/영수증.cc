// https://www.acmicpc.net/problem/5565
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int x, n;
    cin >> x;
    for (int i = 0; i < 9; i++) {
        cin >> n;
        x -= n;
    }
    cout << x;    
    
    return 0;
}
