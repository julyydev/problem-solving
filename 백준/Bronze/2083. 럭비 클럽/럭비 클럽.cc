#include <iostream>
using namespace std;

int main() {
    string name;
    int age, weight;
    
    while (1) {
        cin >> name >> age >> weight;
        if (name == "#") break;
        cout << name;
        if (age > 17 || weight >= 80)
            cout << " Senior\n";
        else
            cout << " Junior\n";
    }
    
    return 0;
}