#include <algorithm>
#include <iostream>
using namespace std;

string sum_binary_number(string b1, string b2) {
    int carry = 0;
    string result = "";

    for (int i = b1.length() - 1; i >= 0; i--) {
        int temp = b1[i] - '0' + b2[i] - '0' + carry;
        result += temp % 2 + '0';
        carry = temp / 2;
    }
    if (carry) result += "1";

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string n;
    cin >> n;
    cout << sum_binary_number(n + "0000", "0000" + n) << "\n";

    return 0;
}