// https://www.acmicpc.net/problem/
// written by julyy

//4344
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        int n, s, sum = 0, count = 0;
        int score[1000];
        cin >> n;
        
        for (int j = 0; j < n; j++) {
            cin >> s;
            score[j] = s;
            sum += s;
        }
        float average = (float)sum / n;
        for (int j = 0; j < n; j++) {
            if (score[j] > average) {
                count++;
            }
        }
        float per = (float)count / n * 100;

        cout << fixed;
        cout.precision(3);
        cout << per << "%\n";
    }

    return 0;
}
