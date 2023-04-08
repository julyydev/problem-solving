#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void backtracking(const int& n, const int& m, const vector<int>& arr,
                  vector<int>& vec) {
    if (vec.size() == m) {
        for (int v : vec) cout << v << " ";
        cout << "\n";
        vec.pop_back();
        return;
    }

    for (int i = 0; i < n; i++) {
        if (find(vec.begin(), vec.end(), arr[i]) != vec.end()) continue;
        vec.push_back(arr[i]);
        backtracking(n, m, arr, vec);
    }
    if (!vec.empty()) vec.pop_back();
    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> arr(N), vec;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    backtracking(N, M, arr, vec);

    return 0;
}