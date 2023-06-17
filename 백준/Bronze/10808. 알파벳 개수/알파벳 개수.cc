#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> dp(26, 0);
    
    for (int i = 0; i < s.length(); i++) dp[s[i] - 'a']++;
    
    for (int i = 0; i < 26; i++) cout << dp[i] << " ";
    cout << "\n";
    
    return 0;
}