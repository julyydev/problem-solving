#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s = "WelcomeToSMUPC";
    cout << s[(n - 1) % 14] << "\n";
    
    return 0;
}