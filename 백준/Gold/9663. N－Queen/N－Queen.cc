#include <iostream>
#include <vector>
using namespace std;
int N;

void backtracking(vector<int>& chess, int& count, int depth) {
    if (depth == N) {
        count++;
        return;
    }

    for (int i = 1; i <= N; i++) {
        bool check = true;
        for (int j = 0; j < depth; j++) {
            if (chess[j] == i || abs(i - chess[j]) == depth - j) {
                check = false;
                break;
            }
        }
        if (!check) continue;

        chess[depth] = i;
        backtracking(chess, count, depth + 1);
    }
    chess[depth] = 0;
    return;
}

int main() {
    cin >> N;
    int count = 0;
    vector<int> chess(N, 0);
    backtracking(chess, count, 0);
    cout << count << "\n";

    return 0;
}