// https://www.acmicpc.net/problem/1212
// written by julyy

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string oct, bin;
    int temp;
    cin >> oct;

    if (oct == "0") {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < oct.length(); i++) {
        temp = oct[i] - '0';
        string sub;
        for (int j = 0; j < 3; j++) {
            sub += temp % 2 + '0';
            temp /= 2;
        }
        for (int j = 2; j >= 0; j--)
            bin += sub[j];
    }

    while (bin[0] == '0') {
        bin.erase(0, 1);
    }

    cout << bin;

    return 0;
}
