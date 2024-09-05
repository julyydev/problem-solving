#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int nums[3];
    for (int i = 0; i < 3; i++) cin >> nums[i];
    sort(nums, nums + 3);
    
    if (nums[0] + nums[1] == nums[2]) cout << "1\n";
    else if (nums[0] * nums[1] == nums[2]) cout << "2\n";
    else cout << "3\n";
    
    return 0;
}