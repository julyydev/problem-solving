#include <iostream>
using namespace std;

int main() {
    char strings[5][15];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 15; j++) strings[i][j] = '\0';

    string s;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        for (int j = 0; j < s.size(); j++) strings[i][j] = s[j];
    }

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < 5; j++) {
            if (strings[j][i] == '\0') continue;
            cout << strings[j][i];
        };
    cout << "\n";

    return 0;
}