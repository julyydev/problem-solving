#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    long long lt, wt, le, we;
    while (t--) {
        cin >> lt >> wt >> le >> we;
        if (lt * wt > le * we) cout << "TelecomParisTech\n";
        else if (lt * wt < le * we) cout << "Eurecom\n";
        else cout << "Tie\n";
    }
    
    return 0;
}