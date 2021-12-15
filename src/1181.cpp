// https://www.acmicpc.net/problem/1181
// written by julyy

/*
vector 중복 제거 하는 법 (erase, unique)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
    if (a.length() == b.length()) {
        int i = 0;
        while (a[i] == b[i]) {
            if (a[i] == '\0' || b[i] == '\0')
                return false;
            i++;
        }
        return a[i] < b[i];
    }
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> vec;
    int N;
    string input;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        vec.push_back(input);
    }

    sort(vec.begin(), vec.end(), compare);
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << '\n';
    }
    
    return 0;
}
