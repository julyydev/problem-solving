#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    
    long long t = 1;
    while (q.size() > 1) {
        for (long long i = 0; i < (t * t * t - 1) % q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
        t++;
    }
    cout << q.front() << "\n";
    
    return 0;
}