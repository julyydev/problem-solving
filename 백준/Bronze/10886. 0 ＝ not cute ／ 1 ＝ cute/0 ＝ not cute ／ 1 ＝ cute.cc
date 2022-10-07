// https://www.acmicpc.net/problem/10886
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int n, c, sum = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> c;
        sum += c;
    }
    if (sum > n / 2)
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";

    return 0;
}
