// https://www.acmicpc.net/problem/8958
// written by julyy

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    char answer[80];

    for (int i = 0; i < n; i++) {
        cin >> answer;
        int sum = 0, count = 0;
        for (int j = 0; j < strlen(answer); j++) {
            if (answer[j] == 'O') {
                count++;
            }
            else {
                count = 0;
            }
            sum += count;
        }
        cout << sum << '\n';
    }
}
