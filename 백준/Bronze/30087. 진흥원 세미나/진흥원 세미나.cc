#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    while (n--) {
        cin >> s;
        if (s == "Algorithm")
            cout << "204\n";
        else if (s == "DataAnalysis")
            cout << "207\n";
        else if (s == "ArtificialIntelligence")
            cout << "302\n";
        else if (s == "CyberSecurity")
            cout << "B101\n";
        else if (s == "Network")
            cout << "303\n";
        else if (s == "Startup")
            cout << "501\n";
        else if (s == "TestStrategy")
            cout << "105\n";
    }
    
    return 0;
}