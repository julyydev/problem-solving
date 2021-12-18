// https://www.acmicpc.net/problem/11005
// written by julyy

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    long n, b;
    string result;
    cin >> n >> b;

    while (n != 0) {
        if  (n % b < 10)
            result += n % b + '0';
        else
            result += n % b - 10 + 'A';
        n /= b;
    }
    reverse(result.begin(), result.end());
    cout << result;
    
    return 0;
}
