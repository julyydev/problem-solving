// https://www.acmicpc.net/problem/1157
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    int count[26] = {0, };
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 65 && word[i] <= 90)
            count[word[i] - 65]++;
        else if (word[i] >= 97 && word[i] <= 122)
            count[word[i] - 97]++;
    }

    int max = -1;
    char ret;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            ret = i + 65;
        }
        else if (count[i] == max)
            ret = '?';    
    }
    cout << ret << '\n';

    return 0;
}
