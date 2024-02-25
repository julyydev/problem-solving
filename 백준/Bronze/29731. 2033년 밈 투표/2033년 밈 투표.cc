#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    bool check = false;
    string s;
    while (n--) {
        getline(cin, s);
        
        if (s == "Never gonna give you up"
           || s == "Never gonna let you down"
           || s == "Never gonna run around and desert you"
           || s == "Never gonna make you cry"
           || s == "Never gonna say goodbye"
           || s == "Never gonna tell a lie and hurt you"
           || s == "Never gonna stop") continue;
        
        check = true;
    }
    
    cout << (check ? "Yes" : "No") << "\n";
}