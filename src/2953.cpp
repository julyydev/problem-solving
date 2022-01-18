// https://www.acmicpc.net/problem/2953
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    vector<pair<int, int>> vec;
    int n, sum;
    pair<int, int> p;

    for (int i = 0; i < 5; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            cin >> n;
            sum += n;
        }
        p.first = i + 1, p.second = sum;
        vec.push_back(p);
    }
    sort(vec.begin(), vec.end(), compare);
    cout << vec[0].first << ' ' << vec[0].second;
    
    return 0;
}
