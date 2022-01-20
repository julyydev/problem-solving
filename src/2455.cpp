// https://www.acmicpc.net/problem/2455
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int m, n, max = 0, sum = 0;

    for (int i = 0; i < 4; i++) {
        cin >> m >> n;
        sum = sum - m + n;
        if (sum > max)
            max = sum;
    }
    cout << max;
    
    return 0;
}
