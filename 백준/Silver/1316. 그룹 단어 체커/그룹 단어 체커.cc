// https://www.acmicpc.net/problem/
// written by julyy

//1316
#include <iostream>
#include <string>
using namespace std;

bool isGroupWord(string str) {
    if (str.length() == 1)
        return true;

    int count[26] = {0, };
    int i = 1;
    while (str[i] != '\0') {
        if (str[i] == str[i - 1])
            str.erase(i, 1);
        else
            i++;

    }
    for (int i = 0; i < str.length(); i++) {
        if (count[str[i] - 'a'] == 0)
            count[str[i] - 'a']++;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++)
        sum += count[i];

    if (sum == str.length())
        return true;
    else
        return false;
}

int main() {
    int n;
    cin >> n;

    int count = n;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (!isGroupWord(word)) 
            count--;
    }
    cout << count;

    return 0;
}
