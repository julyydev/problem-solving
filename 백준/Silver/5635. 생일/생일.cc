#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> student(n);
    
    string s;
    int d, m, y;   
    for (int i = 0; i < n; i++) {
        cin >> s >> d >> m >> y;
        student[i] = {10000 * y + 100 * m + d, s};
    }
    sort(student.begin(), student.end());
    
    cout << student[n - 1].second << "\n" << student[0].second << "\n";
    
    return 0;
}