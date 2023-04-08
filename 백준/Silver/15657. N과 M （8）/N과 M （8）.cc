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

    for (int i = (vec.empty()
                      ? 0
                      : find(arr.begin(), arr.end(), vec.back()) - arr.begin());
         i < n; i++) {
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