#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    FASTIO();
    int H, W, r, water = 0;
    cin >> H >> W;

    vector<vector<bool>> blocks(H, vector<bool>(W, false));

    for (int i = 0; i < W; i++) {
        cin >> r;
        for (int j = 0; j < r; j++) blocks[H - j - 1][i] = true;
    }

    for (int i = 0; i < H; i++) {
        bool check = false;
        int temp_water = 0;
        for (int j = 0; j < W; j++) {
            if (check) {
                if (blocks[i][j]) {
                    water += temp_water;
                    temp_water = 0;
                } else {
                    temp_water++;
                }
            } else {
                if (blocks[i][j]) {
                    check = true;
                }
            }
        }
    }

    cout << water << "\n";

    return 0;
}