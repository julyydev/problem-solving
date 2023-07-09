#include <iostream>
#include <set>
#include <stack>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

void check_cycle(int i, vector<bool>& is_visited, int& count,
                 const vector<int>& students) {
    stack<int> stk;
    set<int> set;
    int temp = i;
    while (set.find(temp) == set.end()) {
        if (is_visited[temp]) return;
        stk.push(temp);
        set.insert(temp);
        is_visited[temp] = true;
        temp = students[temp];
    }

    while (1) {
        count--;
        if (stk.top() == temp) break;
        stk.pop();
    }

    return;
}

int main() {
    FASTIO();
    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        vector<int> students(n + 1);
        for (int i = 1; i <= n; i++) cin >> students[i];

        int count = n;
        vector<bool> is_visited(n + 1, false);
        for (int i = 1; i <= n; i++)
            check_cycle(i, is_visited, count, students);

        cout << count << "\n";
    }

    return 0;
}