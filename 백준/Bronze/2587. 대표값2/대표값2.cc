#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int n;

    for (int i = 0; i < 5; i++) {
        cin >> n;
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end());
    cout << accumulate(vec.begin(), vec.end(), 0) / 5 << "\n";
    cout << vec[2] << "\n";

    return 0;
}