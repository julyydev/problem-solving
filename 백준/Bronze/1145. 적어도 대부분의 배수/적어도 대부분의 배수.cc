#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums(5);
    for (int i = 0; i < 5; i++) cin >> nums[i];
    
    int ans = 1;
    while (1) {
        int count = 0;
        for (int i = 0; i < 5; i++) {
            if (ans % nums[i] == 0) count++;
        }
        
        if (count >= 3) break;
        ans++;
    }
    
    cout << ans << "\n";
    
    return 0;
}