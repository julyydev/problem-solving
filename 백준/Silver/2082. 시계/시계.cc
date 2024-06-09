#include <iostream>
#include <vector>
using namespace std;

const bool digits[10][5][3] = {
    {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}},
    {{0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
};

int get_min_digit(vector<vector<bool>> c) {
    int n = 0;
    for (; n < 10; n++) {
        bool check = true;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 3; j++)
                if (c[i][j] && !digits[n][i][j]) check = false;

        if (check) break;
    }
    return n;
}

vector<vector<bool>> slice_2d_vector(const vector<vector<bool>>& vec, int x) {
    vector<vector<bool>> new_vec(5, vector<bool>(3));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 3; j++) new_vec[i][j] = vec[i][j + x];

    return new_vec;
}

int main() {
    vector<vector<bool>> clock(5, vector<bool>(15, false));
    string s;
    for (int i = 0; i < 5; i++) {
        getline(cin, s);
        for (int j = 0; j < 15; j++) {
            if (s[j] == '#') clock[i][j] = true;
        }
    }

    cout << get_min_digit(slice_2d_vector(clock, 0));
    cout << get_min_digit(slice_2d_vector(clock, 4));
    cout << ":";
    cout << get_min_digit(slice_2d_vector(clock, 8));
    cout << get_min_digit(slice_2d_vector(clock, 12));
    cout << "\n";

    return 0;
}