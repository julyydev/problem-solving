#include <iostream>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

class Ramp {
    int n, l;
    vector<vector<int>> map;

   public:
    Ramp() {}

   private:
    bool is_possible_path(const vector<int>& heights) {
        vector<bool> is_ramp(n, false);
        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (abs(heights[i] - heights[i + 1]) > 1) return false;

            if (heights[i] > heights[i + 1]) {
                int cur = heights[i + 1];
                for (int j = 0; j < l; j++)
                    if (i + j + 1 >= n || heights[i + j + 1] != cur)
                        return false;

                for (int j = 0; j < l; j++) is_ramp[i + j + 1] = true;
                count = 1;
            } else if (heights[i] < heights[i + 1]) {
                if (count < l || i < l - 1) return false;
                for (int j = 0; j < l; j++)
                    if (is_ramp[i - j]) return false;

                for (int j = 0; j < l; j++) is_ramp[i - j] = true;
                count = 1;
            } else {
                count++;
            }
        }

        return true;
    }

   public:
    void init() {
        cin >> n >> l;
        map.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> map[i][j];
    }

    int get_paths() {
        int paths = 0;
        for (int i = 0; i < n; i++)
            if (is_possible_path(map[i])) paths++;

        for (int i = 0; i < n; i++) {
            vector<int> heights(n);
            for (int j = 0; j < n; j++) heights[j] = map[j][i];
            if (is_possible_path(heights)) paths++;
        }

        return paths;
    }
};

int main() {
    FASTIO();
    Ramp ramp;
    ramp.init();
    cout << ramp.get_paths() << "\n";

    return 0;
}