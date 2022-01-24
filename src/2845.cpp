// https://www.acmicpc.net/problem/2845
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int l, p, n;
    vector<int> vec;
    cin >> l >> p;

    for (int i = 0; i < 5; i++) {
        cin >> n;
        vec.push_back(n);
    }

    for (int i = 0; i < 5; i++) {
        cout << vec[i] - l * p << ' ';
    }
    
    return 0;
}
