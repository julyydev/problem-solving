#include <algorithm>
#include <iostream>
#include <vector>
#define io() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

typedef pair<int, int> pi;

int main() {
    io();
    int N, s, e;
    vector<pi> vec;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        vec.push_back(make_pair(s, e));
    }

    sort(vec.begin(), vec.end(), [](const pi& p1, const pi& p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second < p2.second;
    });

    int te = -1;
    int count = 0;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if ((*it).first >= te) {
            te = (*it).second;
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}