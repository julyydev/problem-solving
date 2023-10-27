#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int cacluate_formula(const string& s, const vector<bool>& is_bracket) {
    int result = 0;

    char temp_op = '+';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            temp_op = s[i];
            continue;
        }

        if (is_bracket[i]) {
            int temp = 0;
            switch (s[i + 1]) {
                case '+':
                    temp = (s[i] - '0') + (s[i + 2] - '0');
                    break;
                case '-':
                    temp = (s[i] - '0') - (s[i + 2] - '0');
                    break;
                case '*':
                    temp = (s[i] - '0') * (s[i + 2] - '0');
                    break;
            }

            switch (temp_op) {
                case '+':
                    result += temp;
                    break;
                case '-':
                    result -= temp;
                    break;
                case '*':
                    result *= temp;
                    break;
            }

            i += 2;
            continue;
        }

        switch (temp_op) {
            case '+':
                result += (s[i] - '0');
                break;
            case '-':
                result -= (s[i] - '0');
                break;
            case '*':
                result *= (s[i] - '0');
                break;
        }
    }

    return result;
}

void backtracking(int index, const int& max_index, const string& s,
                  vector<bool> is_bracket, int& max_value) {
    if (index > max_index) {
        max_value = max(max_value, cacluate_formula(s, is_bracket));
        return;
    }

    backtracking(index + 2, max_index, s, is_bracket, max_value);

    is_bracket[index] = true;
    backtracking(index + 4, max_index, s, is_bracket, max_value);
}

int main() {
    FASTIO();
    int n;
    string s;

    cin >> n >> s;

    vector<bool> is_bracket(n, false);
    int max_value = INT32_MIN;

    backtracking(0, n - 3, s, is_bracket, max_value);

    cout << max_value << "\n";

    return 0;
}
