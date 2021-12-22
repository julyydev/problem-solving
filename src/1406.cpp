// https://www.acmicpc.net/problem/1406
// written by julyy

/*
list erase 방법 숙지..!
*/

#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string init;
    char command, c;
    int m;
    cin >> init;
    cin >> m;

    list<char> editor(init.begin(), init.end());
    auto cursor = editor.end();
    for (int i = 0; i < m; i++) {
        cin >> command;

        switch(command) {
            case 'L':
                if (cursor != editor.begin())
                    cursor--;
                break;
            case 'D':
                if (cursor != editor.end())
                    cursor++;
                break;
            case 'B':
                if (cursor != editor.begin())
                    cursor = editor.erase(--cursor);
                break;
            case 'P':
                cin >> c;
                editor.insert(cursor, c);
                break;
        }
    }

    for (auto it = editor.begin(); it != editor.end(); it++)
        cout << *it;
    
    return 0;
}
