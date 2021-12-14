// https://www.acmicpc.net/problem/5622
// written by julyy

#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cin >> word;

    int sec = 0;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] <= 'C')
            sec += 3;
        else if (word[i] <= 'F')
            sec += 4;
        else if (word[i] <= 'I')
            sec += 5;
        else if (word[i] <= 'L')
            sec += 6;
        else if (word[i] <= 'O')
            sec += 7;
        else if (word[i] <= 'S')
            sec += 8;
        else if (word[i] <= 'V')
            sec += 9;
        else if (word[i] <= 'Z')
            sec += 10;
    }
    cout << sec << '\n';

    return 0;
}