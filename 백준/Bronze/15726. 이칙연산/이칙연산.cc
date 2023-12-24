#include <iostream>
using namespace std;

int main() {
    long long a, b, c, temp1, temp2;
    cin >> a >> b >> c;
    
    temp1 = (double)a * b / c, temp2 = (double)a / b * c;
    cout << (temp1 > temp2 ? temp1 : temp2) << "\n";
    
    return 0;
}