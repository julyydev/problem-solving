// https://www.acmicpc.net/problem/4673
// written by julyy

#include <iostream>
#include <cstring>
using namespace std;

int d(int n) {
    int temp = n, sum = n;

    while (temp) {
        sum += temp % 10;
        temp /= 10;
    }

    return sum;
}

int main() {
    bool selfnumber[10001];
    memset(selfnumber, true, sizeof(selfnumber));

    for (int i = 1; i <= 10000; i++) {
        if (selfnumber[i]) {
            int temp = i;
            while (1) {
                temp = d(temp);
                if (temp > 10000) {
                    break;
                }
                selfnumber[temp] = false;
            }
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (selfnumber[i]) {
            cout << i << '\n';
        }
    }

    return 0;
}
