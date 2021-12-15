// https://www.acmicpc.net/problem/1436
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int N, count = 0, find = 666, temp;
    cin >> N;

    while (true) {
        temp = find;

        while (temp > 100) {
            if (temp % 1000 == 666) {
                count++;
                break;
            }
            temp /= 10;
        }

        if (count == N) {
            cout << find << '\n';
            break;
        }
        find++;
    }
    
    return 0;
}
