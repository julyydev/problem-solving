#include <iostream>
using namespace std;

int main() {
    int a, b, s;
    cin >> a >> b;
    s = b - a;
    if (s >= 31) 
        cout << "You are speeding and your fine is $500.\n";
    else if (s >= 21)
        cout << "You are speeding and your fine is $270.\n";
    else if (s >= 1)
        cout << "You are speeding and your fine is $100.\n";
    else
        cout << "Congratulations, you are within the speed limit!\n";
    
    return 0;
}