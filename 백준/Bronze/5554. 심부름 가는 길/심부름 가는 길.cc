// https://www.acmicpc.net/problem/5554
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int t, sum = 0;
    for (int i = 0; i < 4; i++) {
        cin >> t;
        sum += t;
    }
    cout << sum / 60 << '\n' << sum % 60;
    
    return 0;
}
