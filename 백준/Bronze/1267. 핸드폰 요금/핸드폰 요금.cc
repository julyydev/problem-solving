#include <iostream>
using namespace std;

int main() {
    int n, x, y_total = 0, m_total = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        y_total += (x + 30) / 30 * 10;
        m_total += (x + 60) / 60 * 15;
    }
    
    if (y_total < m_total)
        cout << "Y " << y_total << "\n";
    else if (y_total > m_total)
        cout << "M " << m_total << "\n";
    else
        cout << "Y M " << y_total << "\n";
    
    return 0;
}