#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> weights(3);
    for (int i = 0; i < 3; i++) cin >> weights[i];
    sort(weights.begin(), weights.end());
    cout << weights[1] << "\n";
    
    return 0;
}