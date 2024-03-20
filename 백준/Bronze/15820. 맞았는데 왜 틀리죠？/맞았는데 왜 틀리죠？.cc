#include <iostream>
using namespace std;

int main() {
    int s1, s2, x, y;
    cin >> s1 >> s2;
    
    bool sample = true, system = true;
    while (s1--) {
        cin >> x >> y;
        if (x != y) sample = false;
    }
    while (s2--) {
        cin >> x >> y;
        if (x != y) system = false;
    }
    
    if (!sample) {
        cout << "Wrong Answer\n";
        return 0;
    }
    
    if (!system) {
        cout << "Why Wrong!!!\n";
        return 0;
    }
    
    cout << "Accepted\n";
    return 0;
}