// https://www.acmicpc.net/problem/18870
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> vec;
    int N, n;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);
    }
    vector<int> order = {vec.begin(), vec.end()}; // vector copy

    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(order.begin(), order.end(), vec[i]);
        cout << it - order.begin() << ' ';
    }
    
    return 0;
}
