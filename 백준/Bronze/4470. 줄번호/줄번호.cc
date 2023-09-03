#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    
    cin.ignore();
    for (int i = 1; i <= n; i++) {
        getline(cin,s);
        cin.clear();
        cout << i << ". " << s << "\n";
    }
    
    return 0;
}