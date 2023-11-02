#include <algorithm>
#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n, x, result = 0;
    cin >> n;

    vector<int> p_num, m_num;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0)
            p_num.push_back(x);
        else
            m_num.push_back(x);
    }
    sort(p_num.begin(), p_num.end(), greater<int>());
    sort(m_num.begin(), m_num.end());

    if (p_num.size() % 2 == 1) result += p_num.back();
    for (int i = 0; i < (int)p_num.size() - 1; i += 2) {
        if (p_num[i + 1] == 1)
            result += p_num[i] + p_num[i + 1];
        else
            result += p_num[i] * p_num[i + 1];
    }

    if (m_num.size() % 2 == 1) result += m_num.back();
    for (int i = 0; i < (int)m_num.size() - 1; i += 2) {
        result += m_num[i] * m_num[i + 1];
    }

    cout << result << "\n";

    return 0;
}