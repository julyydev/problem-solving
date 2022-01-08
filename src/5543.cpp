// https://www.acmicpc.net/problem/5543
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec1, vec2;
    int p;
    for (int i = 0; i < 3; i++) {
        cin >> p;
        vec1.push_back(p);
    }
    for (int i = 0; i < 2; i++) {
        cin >> p;
        vec2.push_back(p);
    }
    sort(vec1.begin(), vec1.begin() + 3);
    sort(vec2.begin(), vec2.begin() + 2);
    cout << vec1.front() + vec2.front() - 50;
    
    return 0;
}
