// https://www.acmicpc.net/problem/10757
// written by julyy

#include <iostream>
#include <string>
using namespace std;

string big_add(string large, string small) {
    int diff = large.length() - small.length();
    if (diff) {
        string zero = "\0";
        for (int i = 0; i < diff; i++) {
            zero += "0";
        }
        small = zero + small;
    }

    string result;
    int c = 0, add;
    for (int i = 0; i < large.length(); i++) {
        add = large[large.length() - i - 1] - '0' + small[large.length() - i - 1] - '0' + c;
        result += (add % 10) + '0';
        if (add / 10)
            c = 1;
        else
            c = 0;
    }
    if (c)
        result += '1';

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string a, b, result;
    cin >> a >> b;

    if (a.length() > b.length()) {
        result = big_add(a, b);
    }
    else {
        result = big_add(b, a);
    }

    for (int i = 0; i < result.length(); i++) {
        cout << result[result.length() - i - 1];
    }
    
    return 0;
}
