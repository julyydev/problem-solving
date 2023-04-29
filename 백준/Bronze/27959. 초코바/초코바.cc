#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cout << (100 * N >= M ? "Yes" : "No") << "\n";
    return 0;
}