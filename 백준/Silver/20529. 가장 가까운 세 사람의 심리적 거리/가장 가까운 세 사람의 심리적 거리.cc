#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int get_distance(string s1, string s2) {
    int result = 0;
    for (int i = 0; i < 4; i++)
        if (s1[i] != s2[i]) result++;
    return result;
}

int main() {
    FASTIO();
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        vector<string> mbtis(N);
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            mbtis[i] = s;
        }

        if (N >= 33) {
            cout << "0\n";
            continue;
        }

        int min_distance = 100;
        for (int i = 0; i < N - 2; i++) {
            for (int j = i + 1; j < N - 1; j++) {
                for (int k = j + 1; k < N; k++) {
                    int distance = get_distance(mbtis[i], mbtis[j]) +
                                   get_distance(mbtis[i], mbtis[k]) +
                                   get_distance(mbtis[j], mbtis[k]);
                    if (distance < min_distance) min_distance = distance;
                }
            }
        }
        cout << min_distance << "\n";
    }

    return 0;
}