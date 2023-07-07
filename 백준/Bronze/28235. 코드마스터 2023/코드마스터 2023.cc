#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s == "SONGDO")
        cout << "HIGHSCHOOL\n";
    else if (s == "CODE")
        cout << "MASTER\n";
    else if (s == "2023")
        cout << "0611\n";
    else
        cout << "CONTEST\n";
    
    return 0;
}