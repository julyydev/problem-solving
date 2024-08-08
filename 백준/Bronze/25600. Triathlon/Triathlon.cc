#include <iostream>
using namespace std;

int main() {
    int n, a, d, g, max_score = 0;
    cin >> n;
    
    while (n--) {
        cin >> a >> d >> g;
        int score = a * (d + g);
        if (a == d + g) score *= 2;
        max_score = max(max_score, score);
    }
    cout << max_score << "\n";
    
    return 0;
}