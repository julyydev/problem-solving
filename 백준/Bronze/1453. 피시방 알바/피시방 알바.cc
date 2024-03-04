#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, x, count = 0;
    cin >> n;
    
    set<int> s;
    while (n--) {
        cin >> x;
        if (s.find(x) != s.end()) {
            count++;
            continue;
        }
        s.insert(x);
    }
    cout << count << "\n";
    
    return 0;
}