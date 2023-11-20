#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;

    int left = 1, right = 1, sum = 1, count = 0;
    while (right <= n) {
        if (sum > n) {
            sum -= left++;
        } else if (sum < n) {
            sum += ++right;
        } else {
            count++;
            sum += ++right - left++;
        }
    }

    cout << count << "\n";

    return 0;
}