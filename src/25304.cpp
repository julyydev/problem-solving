// https://www.acmicpc.net/problem/25304
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int x, n, a, b, sum = 0;

    cin >> x >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        sum += a * b;
    }

    if (sum == x)
        cout << "Yes\n";
    else
        cout << "No\n";
                
    return 0;
}