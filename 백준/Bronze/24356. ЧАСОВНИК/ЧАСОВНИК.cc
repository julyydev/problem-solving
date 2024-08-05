#include <iostream>
using namespace std;

int main() {
    int t1, m1, t2, m2;
    cin >> t1 >> m1 >> t2 >> m2;
    
    m1 += t1 * 60, m2 += t2 * 60;
    if(m1 > m2) m2 += 24 * 60;
    
    cout << m2 - m1 << " " << (m2 - m1) / 30 << "\n";
    return 0;
}