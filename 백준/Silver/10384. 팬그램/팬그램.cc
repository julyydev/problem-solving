#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    string s;
    for (int i = 1; i <= n; i++) {
        vector<int> count(26, 0);
        getline(cin, s);
        for (auto c : s) {
            if (c >= 'a' && c <= 'z')
                count[c - 'a']++;
            else if (c >= 'A' && c <= 'Z')
                count[c - 'A']++;
        }
       
        int p = 3;
        for (int i = 0; i < 26; i++)
            p = min(p, count[i]);
        
        string result;
        if (p == 0)
            result = "Not a pangram";
        else if (p == 1)
            result = "Pangram!";
        else if (p == 2)
            result = "Double pangram!!";
        else
            result = "Triple pangram!!!";
        
        cout << "Case " << i << ": " << result << "\n";
    }
    return 0;
}