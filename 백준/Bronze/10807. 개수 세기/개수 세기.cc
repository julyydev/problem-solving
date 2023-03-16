#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec(201, 0);
    int N, x, v;
    cin >> N;

    while (N--) {
        cin >> x;
        vec[x + 100]++;
    }

    cin >> v;
    cout << vec[v + 100] << "\n";

    return 0;
}