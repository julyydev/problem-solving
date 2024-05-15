#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s, answer;
    while (n--) {
        cin >> s;
        for (auto c : s)
            if (c == 'S') answer = s;
    }
    cout << answer << '\n';
    
    return 0;
}