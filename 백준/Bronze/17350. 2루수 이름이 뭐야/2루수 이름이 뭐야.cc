#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    
    bool check = false;
    while (n--) {
        cin >> s;
        if (s == "anj") check = true;
    }
    
    cout << (check ? "뭐야;" : "뭐야?") << "\n";
    
    return 0;
}