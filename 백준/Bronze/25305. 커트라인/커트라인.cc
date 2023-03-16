#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int N, k, x;
    cin >> N >> k;

    for (int i = 0; i < N; i++) {
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
    cout << vec[N - k] << "\n";

    return 0;
}