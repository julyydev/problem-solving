#include <iostream>
#include <string>
using namespace std;

int main() {
    int result = 0;
    string s;
    cin >> s;
    
    for (char c : s) {
        if (c == '7') {
            result += 2;
            break;
        }
    }
    
    int n = stoi(s);
    if (n % 7 == 0) result++;
    
    cout << result << "\n";
    
    return 0;
}