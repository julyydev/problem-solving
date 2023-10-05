#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<int> prime;
    prime.push_back(0);
    for (int i = 2; i <= n; i++) {
        if (!is_prime[i]) continue;

        prime.push_back(i);
        for (int j = i * 2; j <= n; j += i) is_prime[j] = false;
    }

    int count = 0, size = prime.size();
    int left = 0, right = 1, sum = prime[left] + prime[right];
    while (1) {
        if (right == size) break;

        if (sum < n) {
            sum += prime[++right];
        } else if (sum > n) {
            sum -= prime[left++];
        } else {
            count++;
            sum += prime[++right] - prime[left++];
        }
    }
    cout << count << "\n";

    return 0;
}