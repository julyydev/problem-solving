#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    string s = to_string(a + b);
    cout << s.length() << "\n";
    
    return 0;
}