#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums(8), origin_nums;
    for (int i = 0; i < 8; i++) cin >> nums[i];
    origin_nums = nums;
    sort(nums.begin(), nums.end(), greater<int>());
    
    int sum = 0;
    vector<int> indexes(5);
    for (int i = 0; i < 5; i++) {
        sum += nums[i];
        indexes[i] = find(origin_nums.begin(), origin_nums.end(), nums[i]) - origin_nums.begin() + 1;
    }
    sort(indexes.begin(), indexes.end());
    
    cout << sum << "\n";
    for (int i : indexes) cout << i << " ";
    cout << "\n";
    
    return 0;
}