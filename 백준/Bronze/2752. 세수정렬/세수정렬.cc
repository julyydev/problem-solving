#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums(3);
    for (int i = 0; i < 3; i++) cin >> nums[i];
    sort(nums.begin(), nums.end());
    for (int n : nums) cout << n << " ";
    cout << "\n";
    return 0;
}