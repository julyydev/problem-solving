// https://www.acmicpc.net/problem/2798
// written by julyy

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, n, sum = 0, temp;
    cin >> N >> M;
    vector<int> card;

    for (int i = 0; i < N; i++) {
        cin >> n;
        card.push_back(n);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                temp = card[i] + card[j] + card[k];
                if (temp > sum && temp <= M)
                    sum = temp;
            }
        }
    }
    cout << sum;

    return 0;
}
