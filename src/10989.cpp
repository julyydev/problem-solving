// https://www.acmicpc.net/problem/10989
// written by julyy

/*
counting sort
*/

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, n;
    int arr[10001] = {0,};
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> n;
        arr[n]++;
    }

    for (int i = 1; i < 10001; i++) {
        if (arr[i]) {
            for (int j = 0; j < arr[i]; j++)
                cout << i << '\n';
        }
    }

    return 0;
}
