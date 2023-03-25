#include <iostream>
#include <vector>
using namespace std;

vector<bool> isBroken(10, false);

bool isPossibleNumber(int n) {
    for (int i = 0; i < to_string(n).size(); i++)
        if (isBroken[stoi(to_string(n).substr(i, 1))]) return false;
    return true;
}

int main() {
    int N, M, x;
    cin >> N >> M;

    while (M--) {
        cin >> x;
        isBroken[x] = true;
    }

    int small = N;
    while (1) {
        if (small == -1) {
            small = -9999999;
            break;
        }
        if (isPossibleNumber(small)) break;
        small--;
    }

    int big = N;
    while (1) {
        if (big == 1000000) {
            big = 9999999;
            break;
        }
        if (isPossibleNumber(big)) break;
        big++;
    }

    cout << min(abs(N - 100), min(N - small + (int)to_string(small).size(),
                                  big - N + (int)to_string(big).size()))
         << "\n";

    return 0;
}