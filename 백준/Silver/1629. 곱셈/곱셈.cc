#include <iostream>
#include <vector>
using namespace std;

string numberToBit(long long number) {
    string bit = "";
    while (number) {
        if (number % 2 == 1)
            bit = "1" + bit;
        else
            bit = "0" + bit;
        number /= 2;
    }
    return bit;
}

int main() {
    long long a, b, c, answer = 1;
    cin >> a >> b >> c;

    string bit = numberToBit(b);
    vector<long long> dp(bit.length());

    dp[0] = a % c;
    for (int i = 1; i < dp.size(); i++) {
        dp[i] = dp[i - 1] * dp[i - 1] % c;
    }

    for (int i = 0; i < bit.length(); i++) {
        if (!bit.substr(bit.length() - i - 1, 1).compare("1")) {
            answer *= dp[i];
            answer %= c;
        }
    }
    cout << answer << "\n";

    return 0;
}