// https://www.acmicpc.net/problem/2751
// written by julyy

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> num(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.begin() + N);
    for (int i = 0; i < N; i++) {
        cout << num[i] << '\n';
    }
    
    return 0;
}
