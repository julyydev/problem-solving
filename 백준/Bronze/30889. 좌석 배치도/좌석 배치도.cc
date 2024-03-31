#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int n;
    cin >> n;

    vector<vector<char>> seat(10, vector<char>(20, '.'));
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int x = s.substr(0, 1)[0] - 'A';
        int y = stoi(s.substr(1)) - 1;
        seat[x][y] = 'o';
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) cout << seat[i][j];
        cout << "\n";
    }

    return 0;
}