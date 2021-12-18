// https://www.acmicpc.net/problem/1373
// written by julyy

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    string bin, oct, sub;
    int num;
    cin >> bin;

    if (bin.length() % 3 == 1)
        bin = "00" + bin;
    else if (bin.length() % 3 == 2)
        bin = "0" + bin;

    for (int i = 0; i < bin.length(); i += 3) {
        sub = bin.substr(i, 3);
        num = 0;
        for (int j = 0; j < 3; j++) {
            if (sub[j] == '1')
                num += 1 << (2 - j);
        }
        oct += num + '0';
    }
    cout << oct;
    
    return 0;
}
