#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    string s, p;
    while (t--) {
        cin >> s >> p;
        int i = 0, time = 0, l = p.length();
        while (1) {
            if (s.find(p, i) == string::npos) break;
            int n = (int)s.find(p, i);
            time += n - i + 1;
            i = n + l;
        }
        time += s.length() - i;
        cout << time << "\n";
    }
    
    return 0;
}