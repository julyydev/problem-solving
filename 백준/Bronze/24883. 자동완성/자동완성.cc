#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    if (s == "N" || s == "n")
        cout << "Naver D2\n";
    else
        cout << "Naver Whale\n";
    
    return 0;
}