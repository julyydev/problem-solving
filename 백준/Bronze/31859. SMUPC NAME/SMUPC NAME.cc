#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, d = 0;
    string s;
    cin >> n >> s;
    
    set<int> set;
    string t = "";
    for (auto c : s) {
        if (set.find(c) != set.end()) {
            d++;
            continue;
        }
        
        set.insert(c);
        t += c;
    }
    t = to_string(1906 + n) + t + to_string(d + 4);
    reverse(t.begin(), t.end());
    t = "smupc_" + t;
    
    cout << t << "\n";
    
    return 0;
}