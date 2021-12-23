// https://www.acmicpc.net/problem/11050
// written by julyy

#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}

int permutation(int n, int k) {
    if (k == 0)
        return 1;
    return n * permutation(n - 1, k - 1);
}

int main() {
    int n, k;
    cin >> n >> k;

    if (k > n / 2)
        cout << permutation (n, n - k) / factorial(n - k);
    else
        cout << permutation (n, k) / factorial(k);
    
    return 0;
}
