#include <iostream>
#include <queue>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

const int max_length = 8;

int main() {
    FASTIO();
    int n;
    cin >> n;

    vector<int> priorities(26, 0);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;

        int mul = 1;
        for (int j = s.length() - 1; j >= 0; j--) {
            priorities[s[j] - 'A'] += mul;
            mul *= 10;
        }
    }

    priority_queue<int> pq;
    for (int i = 0; i < 26; i++) {
        pq.push(priorities[i]);
    }

    int result = 0;
    int greedy_num = 9;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        if (cur == 0) break;

        result += cur * (greedy_num--);
    }

    cout << result << "\n";

    return 0;
}