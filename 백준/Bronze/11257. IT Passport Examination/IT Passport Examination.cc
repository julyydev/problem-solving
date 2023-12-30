#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    int a, b, c;
    while (n--) {
        cin >> s >> a >> b >> c;
        bool pass = true;
        if (a < 10.5 || b < 7.5 || c < 12 || a + b + c < 55) pass = false;
        cout << s << " " << a + b + c << " " << (pass ? "PASS" : "FAIL") << "\n";
    }
    
    return 0;
}