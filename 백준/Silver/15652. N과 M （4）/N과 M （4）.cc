#include <iostream>
#include <vector>
using namespace std;

void backtracking(const int& n, const int& m, vector<int>& vec) {
    if (vec.size() == m) {
        for (int v : vec) cout << v << " ";
        cout << "\n";
        vec.pop_back();
        return;
    }

    for (int i = (vec.empty() ? 1 : vec.back()); i <= n; i++) {
        vec.push_back(i);
        backtracking(n, m, vec);
    }
    if (!vec.empty()) vec.pop_back();
    return;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> vec;
    backtracking(N, M, vec);

    return 0;
}