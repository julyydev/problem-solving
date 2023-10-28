#include <iostream>
using namespace std;

int main() {
    int x, count = 0;
    cin >> x;
    
    x = 1000 - x;
    count += (x / 500);
    x %= 500;
    count += (x / 100);
    x %= 100;
    count += (x / 50);
    x %= 50;
    count += (x / 10);
    x %= 10;
    count += (x / 5);
    x %= 5;
    count += x;
    
    cout << count << "\n";
    
    return 0;
}