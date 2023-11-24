#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> count(9, 0);
    string n;
    cin >> n;
    
    for (char c : n) {
        if (c == '9') count[6]++;
        else count[c - '0']++;
    }
    count[6] = (count[6] + 1) / 2;
    
    int max_count = 0;
    for (int x : count) max_count = max(max_count, x);
    cout << max_count << "\n";
    
    return 0;
}