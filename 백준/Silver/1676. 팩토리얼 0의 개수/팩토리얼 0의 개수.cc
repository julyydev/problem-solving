// https://www.acmicpc.net/problem/1676
// written by julyy

#include <iostream>
using namespace std;

int main() {
    int N, num_of_five = 0, temp;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        temp = i;
        while (temp % 5 == 0) {
            temp /= 5;
            num_of_five++;
        }
    }

    cout << num_of_five;
    
    return 0;
}
