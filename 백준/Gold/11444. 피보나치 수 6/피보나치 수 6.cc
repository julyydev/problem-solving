#include <iostream>
#include <map>
using namespace std;

map<long long, long long> dp;

long long recursion(long long n) {
    if (n == 1 || n == 2) return 1;
    if (n == 0) return 0;

    if (dp.find(n) != dp.end()) return dp.at(n);

    if (n % 2 == 0) {
        long long num1 = recursion(n / 2 - 1);
        long long num2 = recursion(n / 2);
        dp.insert({n, (num1 * 2 + num2) * num2 % 1000000007});
    } else {
        long long num1 = recursion((n + 1) / 2);
        long long num2 = recursion((n - 1) / 2);
        dp.insert({n, (num1 * num1 + num2 * num2) % 1000000007});
    }

    return dp.at(n);
}

int main() {
    long long n;
    cin >> n;
    cout << recursion(n) << "\n";

    return 0;
}