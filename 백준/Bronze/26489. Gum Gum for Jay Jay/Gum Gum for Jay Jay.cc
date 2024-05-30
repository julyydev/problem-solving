#include <iostream>
using namespace std;

int main() {
    int n = 0;
    string s;
    
    cin.ignore(); 
    while (getline(cin, s)) n++;
    cout << n << "\n";
    
    return 0;
}