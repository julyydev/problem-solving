#include <iostream>
using namespace std;

int main() {
    int h1, h2, m1, m2, s1, s2;
    char c;
    cin >> h1 >> c >> m1 >> c >> s1;
    cin >> h2 >> c >> m2 >> c >> s2;
    
    int t1 = h1 * 3600 + m1 * 60 + s1;
    int t2 = h2 * 3600 + m2 * 60 + s2;
    int answer = t2 - t1;
    if (answer < 0) answer += 86400;
    
    cout << answer << "\n";
    
    return 0;
}