// https://www.acmicpc.net/problem/2941
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    int count = word.length();
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == 'c' || word[i] == 's' || word[i] == 'z') {
            if (word[i + 1] == '=') {
                count--;
                i++;
            }
        }
        if (word[i] == 'c' || word[i] == 'd') {
            if (word[i + 1] == '-') {
                count--;
                i++;
            }
        }
        if (word[i] == 'l' || word[i] == 'n') {
            if (word[i + 1] == 'j') {
                count--;
                i++;
            }
        }
        if (word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') {
            count -= 2;
            i += 2;   
        }
    }
    cout << count;

    return 0;
}
