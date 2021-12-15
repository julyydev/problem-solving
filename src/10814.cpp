// https://www.acmicpc.net/problem/10814
// written by julyy

/*
stable sort ..
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, string>> vec;
    int N, age;
    string name;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> age >> name;
        vec.push_back(make_pair(age, name));
    }

    stable_sort(vec.begin(), vec.end(), compare);

    for (int i = 0; i < N; i++) {
        cout << vec[i].first << ' ' << vec[i].second << '\n';
    }
    
    return 0;
}
