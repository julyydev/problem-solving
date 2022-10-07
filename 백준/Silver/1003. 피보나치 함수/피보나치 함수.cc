// https://www.acmicpc.net/problem/1003
// written by julyy

#include <iostream>
using namespace std;

int fibo_arr[41] = {0, 1, };

int fibonacci(int n) {
    if (fibo_arr[n] == 0 && n != 0)
        fibo_arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibo_arr[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        if (n == 0)
            cout << "1 0\n";
        else
            cout << fibonacci(n - 1) << ' ' << fibonacci(n) << '\n'; 
    }
    
    return 0;
}
