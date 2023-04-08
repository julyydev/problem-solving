#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void backtracking(const int& n, const int& m, const vector<int>& arr,
                  vector<int>& vec, set<vector<int>>& set) {
    if (vec.size() == m) {
        vector<int> newVec(m);
        for (int i = 0; i < m; i++) newVec[i] = arr[vec[i]];
        set.insert(newVec);
        vec.pop_back();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vec.empty() && find(vec.begin(), vec.end(), i) != vec.end())
            continue;
        vec.push_back(i);
        backtracking(n, m, arr, vec, set);
    }
    if (!vec.empty()) vec.pop_back();
    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N), vec;
    set<vector<int>> set;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    backtracking(N, M, arr, vec, set);
    for (auto s : set) {
        for (int v : s) cout << v << " ";
        cout << "\n";
    }

    return 0;
}