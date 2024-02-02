#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long reverse_number(long long num) {
    long long result = 0;
    while (num) {
        result *= 10;
        result += num % 10;
        num /= 10;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    long long num;
    
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = reverse_number(num);
    }
    
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < n; i++)
        cout << nums[i] << "\n";
    
    return 0;
}