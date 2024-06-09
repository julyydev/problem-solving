#include <iostream>
#include <sstream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

vector<string> split(string input, const char& dlim) {
    vector<string> result;
    stringstream ss;
    string stringBuffer;

    ss.str(input);
    while (getline(ss, stringBuffer, dlim)) result.push_back(stringBuffer);

    return result;
}

int main() {
    FASTIO();
    int r, c;
    cin >> r >> c;

    vector<vector<char>> puzzle(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> puzzle[i][j];

    string answer = "zzzzzzzzzzzzzzzzzzzzz";

    for (int i = 0; i < r; i++) {
        vector<char> vec = puzzle[i];

        vector<string> strings = split(string(vec.data(), vec.size()), '#');

        for (string s : strings) {
            if (s.length() < 2) continue;
            answer = min(answer, s);
        }
    }

    for (int i = 0; i < c; i++) {
        vector<char> vec(r);
        for (int j = 0; j < r; j++) vec[j] = puzzle[j][i];

        vector<string> strings = split(string(vec.data(), vec.size()), '#');

        for (string s : strings) {
            if (s.length() < 2) continue;
            answer = min(answer, s);
        }
    }

    cout << answer << "\n";

    return 0;
}