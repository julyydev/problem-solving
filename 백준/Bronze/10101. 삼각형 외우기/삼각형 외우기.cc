#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c != 180) {
        cout << "Error\n";
        return 0;
    }
    
    if (a == 60 && b == 60 && c == 60)
        cout << "Equilateral\n";
    else if (a != b && b != c && c != a)
        cout << "Scalene\n";
    else
        cout << "Isosceles\n";
    
    return 0;
}