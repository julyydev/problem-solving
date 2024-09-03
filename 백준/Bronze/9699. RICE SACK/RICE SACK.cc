#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int max_weight = 0, weight;
        for (int j = 0; j < 5; j++) {
            cin >> weight;
            max_weight = max(max_weight, weight);
        }
        cout << "Case #" << i << ": " << max_weight << "\n";
    }
    
    return 0;
}