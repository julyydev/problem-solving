#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, i, j;
    cin >> N >> M;
    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++) {
        vec[i] = i;
    }

    while (M--) {
        cin >> i >> j;
        int temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    for (int i = 1; i <= N; i++) cout << vec[i] << " ";
    cout << "\n";

    return 0;
}
