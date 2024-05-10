#include <iostream>
using namespace std;

int main() {
    long long n, second = 1;
    cin >> n;
    
    for (int i = 1; i <= n; i++) second *= i;
    cout << second / (60 * 60 * 24 * 7) << "\n";
       
    return 0;
}