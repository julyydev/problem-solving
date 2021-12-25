// https://www.acmicpc.net/problem/1966
// written by julyy

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int import;
    int index;
} document;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    document d;
    int t, n, m, imp, count;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        count = 0;
        queue<document> q;
        vector<int> vec;

        for (int j = 0; j < n; j++) {
            cin >> imp;
            d.import = imp;
            d.index = j;
            q.push(d);
            vec.push_back(imp);
        }
        sort(vec.begin(), vec.end());

        while (1) {
            if (q.front().import == vec.back()) {
                count++;
                if(q.front().index == m)
                    break;
                q.pop();
                vec.pop_back();
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
        cout << count << '\n';
    }
    
    return 0;
}
