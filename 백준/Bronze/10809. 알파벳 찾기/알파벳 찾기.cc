// https://www.acmicpc.net/problem/10809
// written by julyy

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
    int alphabet[26];
    memset(alphabet, -1, sizeof(alphabet));

    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        if (alphabet[word[i] - 97] == -1)
            alphabet[word[i] - 97] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }

    return 0;
}