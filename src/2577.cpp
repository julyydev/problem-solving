// https://www.acmicpc.net/problem/2577
// written by julyy

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, mul;
    int arr[10];
    memset(arr, 0, sizeof(arr));

    cin >> a >> b >> c;
    mul = a * b * c;

    while (mul) {
        arr[mul % 10]++;
        mul /= 10;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "\n";
    }

	return 0;
}
