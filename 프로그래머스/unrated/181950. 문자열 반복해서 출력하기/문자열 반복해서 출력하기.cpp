#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int n;
    cin >> str >> n;
    
    while (n--)
        cout << str;
    cout << "\n";
    
    return 0;
}