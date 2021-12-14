// https://www.acmicpc.net/problem/2231
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, sum, temp;
    cin >> N;

    for (int i = 1; i < N; i++) {
        sum = i, temp = i;
        while (temp) {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == N) {
            cout << i;
            return 0;;
        }
    }
    cout << 0;

    return 0;
}
