#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    int x;
    queue<pair<string, int>> q;
    for (int i = 0; i < n; i++) {
        cin >> s >> x;
        q.push({s, x});
    }
    
    while (q.size() > 1) {
        int c = q.front().second - 1;
        q.pop();
        
        while (c--) {
            q.push(q.front());
            q.pop();
        }
        
        q.pop();
    }
    cout << q.front().first << "\n";
    
    return 0;
}