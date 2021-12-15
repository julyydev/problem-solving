// https://www.acmicpc.net/problem/1427
// written by julyy

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string N;
    cin >> N;
    vector<int> num;

    for (int i = 0; i < N.length(); i++) {
        num.push_back(N[i] - '0');
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < N.length(); i++) {
        cout << num.back();
        num.pop_back();
    }
    
    return 0;
}
