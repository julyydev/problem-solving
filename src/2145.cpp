// https://www.acmicpc.net/problem/2145
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int n, temp;
    
    while (1) {
        cin >> n;
        if (n == 0)
            break;
        
        while (n >= 10) {
            temp = 0;
            while (n != 0) {
                temp += n % 10;
                n /= 10;
            }
            n = temp;
        }
        cout << n << '\n';
    }
    
    return 0;
}
