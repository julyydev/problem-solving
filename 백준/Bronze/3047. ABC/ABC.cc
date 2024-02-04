#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums(3);
    string s;
    
    for (int i = 0; i < 3; i++)
        cin >> nums[i];
    cin >> s;
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < 3; i++)
        cout << nums[s[i] - 'A'] << " ";
    cout << "\n";
    
    return 0;
}