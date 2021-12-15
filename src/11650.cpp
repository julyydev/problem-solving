// https://www.acmicpc.net/problem/11650
// written by julyy

/*
좌표는 pair를 사용하는게 편함
compare를 사용한 sort()
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> vec;
    int N, x, y;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
    
    return 0;
}