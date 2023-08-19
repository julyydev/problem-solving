#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct Data {
    int num, count;
    Data() {}
    Data(int num, int count) : num(num), count(count) {}
    bool operator<(const Data& d) const {
        if (count == d.count) return num < d.num;
        return count < d.count;
    }
};

class Array2D {
    int r, c, k;
    int r_num, c_num;
    int time;
    vector<vector<int>> arr;

   public:
    Array2D(vector<vector<int>> init_arr, int r, int c, int k)
        : arr(init_arr), r(r), c(c), k(k), r_num(3), c_num(3), time(0) {}

   private:
    bool is_satisfy_value() { return arr[r - 1][c - 1] == k; }

    void r_operation() {
        int max_c_num = c_num;
        for (int i = 0; i < r_num; i++) {
            map<int, int> map;
            for (int j = 0; j < 100; j++) {
                if (arr[i][j] == 0) continue;

                if (map.find(arr[i][j]) == map.end()) {
                    map.insert({arr[i][j], 1});
                } else
                    map[arr[i][j]]++;
            }

            vector<Data> temp;
            for (auto m : map) temp.push_back({m.first, m.second});
            sort(temp.begin(), temp.end());
            max_c_num = max(max_c_num, (int)temp.size() * 2);

            vector<int> new_row(100, 0);
            for (int j = 0; j < temp.size(); j++) {
                if (j >= 50) break;
                new_row[2 * j] = temp[j].num;
                new_row[2 * j + 1] = temp[j].count;
            }
            arr[i] = new_row;
        }
        c_num = min(max_c_num, 100);
    }

    void c_operation() {
        int max_r_num = r_num;
        for (int i = 0; i < c_num; i++) {
            map<int, int> map;
            for (int j = 0; j < 100; j++) {
                if (arr[j][i] == 0) continue;

                if (map.find(arr[j][i]) == map.end()) {
                    map.insert({arr[j][i], 1});
                } else
                    map[arr[j][i]]++;
            }

            vector<Data> temp;
            for (auto m : map) temp.push_back({m.first, m.second});
            sort(temp.begin(), temp.end());
            max_r_num = max(max_r_num, (int)temp.size() * 2);

            vector<int> new_column(100, 0);
            for (int j = 0; j < temp.size(); j++) {
                if (j >= 50) break;
                new_column[2 * j] = temp[j].num;
                new_column[2 * j + 1] = temp[j].count;
            }
            for (int j = 0; j < 100; j++) arr[j][i] = new_column[j];
        }
        r_num = min(max_r_num, 100);
    }

   public:
    void operation() {
        while (1) {
            if (time > 100) {
                time = -1;
                return;
            }
            if (is_satisfy_value()) return;

            if (r_num >= c_num)
                r_operation();
            else
                c_operation();

            time++;
        }
    }

    int get_time() { return time; }
};

int main() {
    FASTIO();
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> init_arr(100, vector<int>(100, 0));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> init_arr[i][j];

    Array2D array_2d(init_arr, r, c, k);
    array_2d.operation();
    cout << array_2d.get_time() << "\n";

    return 0;
}