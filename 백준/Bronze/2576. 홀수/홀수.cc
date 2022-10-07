// https://www.acmicpc.net/problem/2576
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec;
    int n, sum = 0;
    
    for (int i = 0; i < 7; i++) {
        cin >> n;
        if (n % 2 == 1) {
            vec.push_back(n);
            sum += n;
        }
    }
    if (vec.empty())
        cout << -1;
    else {
        sort(vec.begin(), vec.end());
        cout << sum << '\n' << vec.front();
    }
    
    return 0;
}
