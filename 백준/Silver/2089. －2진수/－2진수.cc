// https://www.acmicpc.net/problem/2089
// written by julyy

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    long long n;
    cin >> n;
    string result;

    if (n == 0) {
        cout << 0;
        return 0;
    }

    while (n != 0) {
        if (n % -2 == 0) {
            result += '0';
            n /= -2;
        }
        else {
            result += '1';
            n = (n - 1) / -2;
        }
    }
    
    for (int i = result.length() - 1; i >= 0; i--) {
        cout << result[i];
    }
    
    return 0;
}
