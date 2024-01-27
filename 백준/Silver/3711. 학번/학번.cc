#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, g;
    cin >> n;
    
    while (n--) {
        cin >> g;
        vector<int> student(g);
        for (int i = 0; i < g; i++) cin >> student[i];
        
        int d = 1;
        while (1) {
            set<int> s;
            bool check = true;
            for (int i = 0; i < g; i++) {
                if (s.find(student[i] % d) != s.end()) {
                    check = false;
                    break;
                }
                s.insert(student[i] % d);
            }
            
            if (check) break;
            d++;
        }
        cout << d << "\n";
    }
    
    return 0;
}