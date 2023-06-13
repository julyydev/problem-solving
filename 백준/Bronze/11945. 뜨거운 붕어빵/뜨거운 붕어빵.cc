#include <iostream>
using namespace std;

int main() {
    int N, M;
    string s;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = s.length() - 1; j >= 0; j--) cout << s[j];
        cout << "\n";
    }
    
    return 0;
}