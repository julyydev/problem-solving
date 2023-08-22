#include <iostream>
using namespace std;

int main() {
    int m, d, date;
    cin >> m >> d;
    date = m * 100 + d;

    if (date < 218)
        cout << "Before\n";
    else if (date > 218)
        cout << "After\n";
    else
        cout << "Special\n";

    return 0;
}