#include <iostream>
using namespace std;

int main() {
    char grade, symbol;
    double value;
    cin >> grade;
    if (grade == 'F') {
        cout << "0.0\n";
        return 0;
    }

    cin >> symbol;
    if (symbol == '+')
        value = 0.3;
    else if (symbol == '0')
        value = 0.0;
    else
        value = -0.3;

    cout.precision(1);
    cout << fixed << (double)(4 - (grade - 'A') + value) << "\n";

    return 0;
}