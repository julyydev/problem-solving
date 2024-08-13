#include <iostream>
using namespace std;

const string winners[] = {"ITMO", "SPbSU", "SPbSU", "ITMO", "ITMO",
                          "SPbSU", "ITMO", "ITMO", "ITMO", "ITMO",
                          "ITMO", "PetrSU, ITMO", "SPbSU", "SPbSU",
                          "ITMO", "ITMO", "ITMO", "ITMO", "SPbSU",
                          "ITMO", "ITMO", "ITMO", "ITMO", "SPbSU", "ITMO"};

int main() {
    int y;
    cin >> y;
    cout << winners[y - 1995] << "\n";
    
    return 0;
}